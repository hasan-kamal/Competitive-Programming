/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

vi a;
vi tree;

void build_tree(int v, int start, int end){
	if(start == end){
		tree[v] = a[start];
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	tree[v] = tree[2 * v] ^ tree[2 * v + 1];
}

int query_tree(int v, int start, int end, int l, int r){
	if(start == l && end == r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	if(r <= mid)
		return query_tree(2 * v, start, mid, l, r);
	else if(mid < l)
		return query_tree(2 * v + 1, mid + 1, end, l, r);
	else
		return query_tree(2 * v, start, mid, l, mid) ^ query_tree(2 * v + 1, mid + 1, end, mid + 1, r);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	a = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	tree = vi(4 * n, 0);
	build_tree(1, 1, n);

	int q, l, r;
	cin >> q;
	while(q--){
		cin >> l >> r;
		cout << query_tree(1, 1, n, l, r) << endl;
	}			

	return 0;
}