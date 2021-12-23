/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

vi tree;
string s;

void build_tree(int v, int start, int end){
	if(start == end){
		tree[v] = (s[start - 1] - '0');
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	tree[v] = tree[2 * v] + tree[2 * v + 1];
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
		return query_tree(2 * v, start, mid, l, mid) + query_tree(2 * v + 1, mid + 1, end, mid + 1, r);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		cin >> s;
		int n = s.length();

		tree = vi(4 * n + 1, 0);
		build_tree(1, 1, n);

		int q;
		cin >> q;
		int i, j;
		while(q--){
			cin >> i >> j;
			int sum = query_tree(1, 1, n, i, j);
			if(sum % 9 == 0)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}