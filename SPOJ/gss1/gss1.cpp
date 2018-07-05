/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
using namespace std;

typedef vector<int> vi;
typedef struct{
	int left_best_sum;
	int right_best_sum;
	int sum;
	int best_subarray_sum;
} node;
typedef vector<node> vnode;

int max2(int x, int y){
	return x > y ? x : y;
}

int max3(int x, int y, int z){
	return max2(x, max2(y, z));
}

vnode tree;
node build(vi &a, int v, int start, int end){

	if(start == end){
		tree[v].sum = tree[v].left_best_sum = tree[v].right_best_sum = tree[v].best_subarray_sum = a[start];
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	node l_side = build(a, 2 * v, start, mid);
	node r_side = build(a, 2 * v + 1, mid + 1, end);

	tree[v].sum = l_side.sum + r_side.sum;
	tree[v].left_best_sum = max2(l_side.left_best_sum, l_side.sum + r_side.left_best_sum);
	tree[v].right_best_sum = max2(r_side.right_best_sum, r_side.sum + l_side.right_best_sum);
	tree[v].best_subarray_sum = max3(l_side.best_subarray_sum, l_side.right_best_sum + r_side.left_best_sum, r_side.best_subarray_sum);

	return tree[v];

}

node query(int v, int start, int end, int x, int y){

	if(x <= start && end <= y)
		return tree[v];

	int mid = start + (end - start) / 2;

	if(x > mid)
		return query(2 * v + 1, mid + 1, end, x, y);

	if(y <= mid)
		return query(2 * v, start, mid, x, y);

	node l_side = query(2 * v, start, mid, x, y);
	node r_side = query(2 * v + 1, mid + 1, end, x, y);

	node current;
	current.sum = l_side.sum + r_side.sum;
	current.left_best_sum = max2(l_side.left_best_sum, l_side.sum + r_side.left_best_sum);
	current.right_best_sum = max2(r_side.right_best_sum, r_side.sum + l_side.right_best_sum);
	current.best_subarray_sum = max3(l_side.best_subarray_sum, l_side.right_best_sum + r_side.left_best_sum, r_side.best_subarray_sum);

	return current;

}

int main(){

	int n;
	scanf("%d", &n);

	vi a = vi(n + 1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	tree = vnode(4 * n);
	build(a, 1, 1, n);

	int m;
	scanf("%d", &m);

	while(m--){

		int x, y;
		scanf("%d %d", &x, &y);

		printf("%d\n", query(1, 1, n, x, y).best_subarray_sum);
	}

	return 0;
}