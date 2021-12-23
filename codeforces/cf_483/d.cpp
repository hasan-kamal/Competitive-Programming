/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int maximum(int a, int b){
	return a > b ? a : b;
}

typedef struct{
	node *left;
	node *right;
	int val;
} node;

void add(node *root, int value, int bit_index){
	int bit = (value >> bit_index) & 1;
	if(bit == 0){
		if(root->left == NULL){
			root->left = (node *)malloc(sizeof(node));
			root->left->left = NULL;
			root->left->right = NULL;
		}
		if(bit_index == 0)
			root->left->val = value;
		if(bit_index - 1 >= 0)
			add(root.left, value, bit_index - 1);
	}else{
		if(root->right == NULL){
			root->right = (node *)malloc(sizeof(node));
			root->right->left = NULL;
			root->right->right = NULL;
		}
		if(bit_index == 0)
			root->right->val = value;
		if(bit_index - 1 >= 0)
			add(root.right, value, bit_index - 1);
	}
}

int traverse_xor(node *root, int value){
	node *cur = root;
	
	int bit_number = 31;
	while(bit_number >= 0){
		int bit = (value >> bit_number) & 1;
		if(bit == 0){
			if(cur->right != NULL)
				cur = cur->right;
			else
				cur = cur->left;
		}else{
			if(cur->left != NULL)
				cur = cur->left;
			else
				cur = cur->right;
		}

		bit_number--;
	}

	return value ^ cur->val;
}

int maximum_xor(vi left_arr, vi right_arr){
	// build trie using elements of left_arr
	// then traverse to get max xor possible

	node *root = (node *)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	for(int x : left_arr){
		add(root, x, 31);
	}

	int ans = INT_MIN;
	for(int x : right_arr){
		ans = maximum(ans, traverse_xor(root, x));
	}

	return ans;
}

vi a;
vii tree;
void build_tree(int v, int start, int end){
	if(start == end){
		tree[v] = make_pair(a[start], 0);
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	tree[v].first = maximum(tree[2 * v].first, tree[2 * v + 1].first);
	tree[v].second = maximum(tree[2 * v].second, tree[2 * v + 1].second)

	// combine step
	int l_size = mid - start + 1; 
	vi left_arr(l_size);
	for(int i = 0; i < l_size; i++){
		left_arr[i] = a[start + i];
	}

	int r_size = end - mid;
	vi right_arr(r_size);
	for(int i = 0; i < r_size; i++){
		right_arr[i] = a[mid + 1 + i];
	}

	tree[v].second = maximum(tree[v].second, max_xor(left_arr, right_arr));
}

int query(int v, int left, int right, int start, int end){
	if(start <= left && right <= end){
		return maximum(tree[v].first, tree[v].second);
	}

	int mid = left + (right - left) / 2;
	if(end <= mid){
		return query(2 * v, left, mid, start, end);
	}
	if(mid < start){
		return query(2 * v + 1, mid + 1, right, start, end);
	}

	int l_ans = query(2 * v, left, mid, start, mid);
	int r_ans = query(2 * v + 1, mid + 1, right, mid + 1, end);
	int ans = maximum(l_ans, r_ans);

	// combine step
	int l_size = mid - start + 1; 
	vi left_arr(l_size);
	for(int i = 0; i < l_size; i++){
		left_arr[i] = a[start + i];
	}

	int r_size = end - mid;
	vi right_arr(r_size);
	for(int i = 0; i < r_size; i++){
		right_arr[i] = a[mid + 1 + i];
	}

	ans = maximum(ans, max_xor(left_arr, right_arr));
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	a = vi(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	tree = vii(5 * n, make_pair(0, 0));
	build_tree(1, 1, n);

	int q;
	cin >> q;

	int l, r;
	while(q--){
		cin >> l >> r;
		cout << query(1, 1, n, l, r) << endl;
	}

	return 0;
}