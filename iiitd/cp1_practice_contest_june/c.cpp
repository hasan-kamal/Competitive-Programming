/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

vi tree;
vi a;

int count_zeroes(int n){
	if(n == 0)
		return 1;

	if(n < 0)
		n = -1 * n;

	int ans = 0;
	while(n > 0){
		if(n % 10 == 0){
			ans++;
		}
		n /= 10;
	}
	return ans;
}

void build_tree(int v, int start, int end){

	if(start == end){
		tree[v] = count_zeroes(a[start]);
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int query_tree(int v, int start, int end, int k){
	
	if(k > tree[v])
		return -1;

	if(start == end)
		return start - 1;

	int mid = start + (end - start) / 2;
	if(k <= tree[2 * v])
		return query_tree(2 * v, start, mid, k);
	else
		return query_tree(2 * v + 1, mid + 1, end, k - tree[2 * v]);

}

void update_tree(int v, int start, int end, int index, int new_val){

	if(start == end){
		tree[v] = count_zeroes(new_val);
		return;
	}

	int mid = start + (end - start) / 2;
	if(index <= mid)
		update_tree(2 * v, start, mid, index, new_val);
	else
		update_tree(2 * v + 1, mid + 1, end, index, new_val);

	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

void disp_tree(int v, int start, int end, int indentation = 0){
	string ind = "";
	for(int i = 0; i < indentation; i++)
		ind += "\t";
	cout << ind << "node v=" << v << " [" << start << ", " << end << "] tree[v]=" << tree[v] << endl;
	if(start == end)
		return;
	int mid = start + (end - start) / 2;
	disp_tree(2 * v, start, mid, indentation + 1);
	disp_tree(2 * v + 1, mid + 1, end, indentation + 1);
}

int main(){

	int n;
	cin >> n;

	a = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	tree = vi(4 * n);
	build_tree(1, 1, n);

	int q, q_type, i, v, k;
	cin >> q;
	while(q--){

		cin >> q_type;

		if(q_type == 0){
			cin >> i >> v;
			update_tree(1, 1, n, i + 1, v);
		}else{
			cin >> k;
			cout << query_tree(1, 1, n, k) << endl;
		}

		// cout << "--------" << endl;
		// disp_tree(1, 1, n);
		// cout << "--------" << endl;

	}

	return 0;
}