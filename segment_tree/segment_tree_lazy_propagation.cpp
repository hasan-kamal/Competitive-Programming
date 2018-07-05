/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

vi tree;
vi lazy;
void build_tree(ll v, ll start, ll end){

	if(start == end){
		tree[v] = 0;
		lazy[v] = 0;
		return;
	}

	ll mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

void update_tree(ll v, ll start, ll end, ll l, ll r, ll val){

	if(start == l && end == r){
		tree[v] += (end - start + 1) * val;
		if(start != end){
			lazy[2 * v] += val;
			lazy[2 * v + 1] += val;
		}
		return;
	}

	ll mid = start + (end - start) / 2;

	if(mid < l){
		update_tree(2 * v + 1, mid + 1, end, l, r, val);
		tree[v] += (r - l + 1) * val; // important!, don't use tree[v] = tree[2 * v] + tree[2 * v + 1] here!! 
	}else if(r <= mid){
		update_tree(2 * v, start, mid, l, r, val);
		tree[v] += (r - l + 1) * val;
	}else{
		update_tree(2 * v, start, mid, l, mid, val);
		update_tree(2 * v + 1, mid + 1, end, mid + 1, r, val);
		tree[v] += (r - l + 1) * val;
	}

}

ll query_tree(ll v, ll start, ll end, ll l, ll r){

	tree[v] += (end - start + 1) * lazy[v];
	if(start != end){
		lazy[2 * v] += lazy[v];
		lazy[2 * v + 1] += lazy[v];
	}
	lazy[v] = 0;

	if(start == l && end == r){
		return tree[v];
	}

	ll mid = start + (end - start) / 2;
	if(mid < l){
		return query_tree(2 * v + 1, mid + 1, end, l, r);
	}

	if(r <= mid){
		return query_tree(2 * v, start, mid, l, r);
	}

	ll l_child = query_tree(2 * v, start, mid, l, mid);
	ll r_child = query_tree(2 * v + 1, mid + 1, end, mid + 1, r);
	return l_child + r_child;

}

void show_tree(ll v, ll start, ll end, ll indentation){

	// string str;
	// for(ll i = 0; i < indentation; i++)
	// 	str+=" ";
	// cout << str << "node #" << v << " [" << start << ", " << end << "] ";
	// cout << str << "tree[v]=" << tree[v] << " lazy[v]=" << lazy[v] << endl;

	if(start != end){
		ll mid = start + (end - start) / 2;
		show_tree(2 * v, start, mid, indentation + 1);
		show_tree(2 * v + 1, mid + 1, end, indentation + 1);
	}

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	while(t--){

		ll n;
		cin >> n;

		tree = vi(4 * n, 0);
		lazy = vi(4 * n, 0);
		build_tree(1, 1, n);

		ll q;
		cin >> q;

		ll ch, l, r, val;
		while(q--){

			cin >> ch;

			if(ch == 0){
				//update
				cin >> l >> r >> val;
				update_tree(1, 1, n, l, r, val);
			}else{
				//query
				cin >> l >> r;
				ll sum = query_tree(1, 1, n, l, r);

				cout << sum << endl;
			}

			//show_tree(1, 1, n, 0);
		}

	}

	return 0;
}