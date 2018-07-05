/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

vll tree;
vll lazy;
void build_segtree(int v, ll start, ll end){
	if(start == end){
		tree[start] = 0;
		lazy[start] = 0;
		return;
	}

	int mid = start + (end - start) / 2;
	build_segtree(2 * v, start, mid);
	build_segtree(2 * v + 1, mid + 1, end);
}

void add_segtree(int v, int start, ll end, int l, int r, int increment){

	tree[v] += ( (end - start + 1) * lazy[v] );
	if(start != end){
		lazy[2 * v] += lazy[v];
		lazy[2 * v + 1] += lazy[v];
	}
	lazy[v] = 0;

	if(r < start || end < l)
		return;

	if(l <= start && end <= r){

		tree[v] += ( (end - start + 1) * increment );

		if(start != end){
			lazy[2 * v] += increment;
			lazy[2 * v + 1] += increment;
		}

		return;
	}

	int mid = start + (end - start) / 2;
	add_segtree(2 * v, start, mid, l, r, increment);
	add_segtree(2 * v + 1, mid + 1, end, l, r, increment);

	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

ll query_segtree(int v, int start, int end, int l, int r){

	tree[v] += ( (end - start + 1) * lazy[v] );	
	
	if(start != end){
		lazy[2 * v] += lazy[v];
		lazy[2 * v + 1] += lazy[v];
	}

	lazy[v] = 0;

	if(r < start || end < l){
		return 0;
	}

	if(l <= start && end <= r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	return query_segtree(2 * v, start, mid, l, r) + query_segtree(2 * v + 1, mid + 1, end, l, r);

}

int main(){

	int t, n, c;
	cin >> t;

	while(t--){
		
		cin >> n >> c;

		tree = vll(4 * n);
		lazy = vll(4 * n);
		build_segtree(1, 1, n);

		int choice, p, q, v;
		for(int i = 0; i < c; i++){
			cin >> choice;

			if(choice == 0){
				cin >> p >> q >> v;
				add_segtree(1, 1, n, p, q, v);
				continue;
			}

			cin >> p >> q;
			cout << query_segtree(1, 1, n, p, q) << endl;
		}

	}

	return 0;
}