/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#define M 1000000009
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

vll fib;
vll fib_sum;
vll tree;
vvpll lazy;
void build_tree(ll v, ll start, ll end, vll &a){

	if(start == end){
		tree[v] = a[start];
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid, a);
	build_tree(2 * v + 1, mid + 1, end, a);
	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

void update_tree(ll v, ll start, ll end, ll l, ll r, ll fib_low, ll fib_hi){

	if(start == l && end == r){
		ll increment = ( fib_sum[fib_hi] - fib_sum[fib_low - 1] + M ) % M;
		tree[v] = ( tree[v] + increment ) % M;
		if(start == end)
			return;
		ll fib_mid = fib_low + (fib_hi - fib_low) / 2;
		lazy[2 * v].push_back(make_pair(fib_low, fib_mid));
		lazy[2 * v + 1].push_back(make_pair(fib_mid + 1, fib_hi));
		return;
	}

	ll mid = start + (end - start) / 2;
	if(mid < l){
		update_tree(2 * v + 1, mid + 1, end, l, r, fib_low, fib_hi);
	}else if(r <= mid){
		update_tree(2 * v, start, mid, l, r, fib_low, fib_hi);
	}else{
		ll fib_mid = fib_low + (mid - l);
		update_tree(2 * v, start, mid, l, mid, fib_low, fib_mid);
		update_tree(2 * v + 1, mid + 1, end, mid + 1, r, fib_mid + 1, fib_hi);
	}

	ll increment = (fib_sum[fib_hi] - fib_sum[fib_low - 1] + M) % M;
	tree[v] = ( tree[v] + increment ) % M;

}

ll query_tree(ll v, ll start, ll end, ll l, ll r){

	//handle lazy updation
	for(pll &i : lazy[v]){
		ll increment = (fib_sum[i.second] - fib_sum[i.first - 1] + M) % M;
		tree[v] = ( tree[v] + increment ) % M;
		
		if(start != end){
			ll fib_mid = i.first + (i.second - i.first) / 2;
			lazy[2 * v].push_back(make_pair(i.first, fib_mid));
			lazy[2 * v + 1].push_back(make_pair(fib_mid + 1, i.second));
		}
	}
	
	lazy[v].clear();

	if(start == l && end == r){
		return tree[v];
	}

	ll mid = start + (end - start) / 2;
	if(mid < l){
		return query_tree(2 * v + 1, mid + 1, end, l, r);
	}else if(r <= mid){
		return query_tree(2 * v, start, mid, l, r);
	}else{
		ll l_child = query_tree(2 * v, start, mid, l, mid);
		ll r_child = query_tree(2 * v + 1, mid + 1, end, mid + 1, r);
		return ( l_child + r_child ) % M;
	}

}

void display_tree(ll v, ll start, ll end, ll indentation){

	string str;
	for(int i = 0; i < indentation; i++)
		str += "\t";

	cout << str << "node v=" << v << " [" << start << ", " << end << "]" << endl;
	cout << str << "tree[v]=" << tree[v] << endl;
	for(pll &x : lazy[v]){
		cout << str << "lazy[v] includes f(" << x.first << ") to f(" << x.second << ")" << endl;
	}

	if(start != end){
		ll mid = start + (end - start) / 2;
		display_tree(2 * v, start, mid, indentation + 1);
		display_tree(2 * v + 1, mid + 1, end, indentation + 1);
 	}

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	fib = vll(n + 1);
	fib[1] = 1;
	fib[2] = 1;
	for(int i = 3; i <= n; i++){
		fib[i] = ( fib[i - 1] + fib[i - 2] ) % M;
	}

	fib_sum = vll(n + 1);
	fib_sum[0] = 0;
	fib_sum[1] = 1;
	for(int i = 2; i <=n; i++){
		fib_sum[i] = ( fib_sum[i - 1] + fib[i] ) % M;
	}

	vll a = vll(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	tree = vll(4 * n);
	lazy = vvpll(4 * n, vpll());
	build_tree(1, 1, n, a);

	ll q_type, l, r;
	while(m--){

		cin >> q_type >> l >> r;

		if(q_type == 1){
			//update
			update_tree(1, 1, n, l, r, 1, r - l + 1);
		}else{
			//query
			ll ans = query_tree(1, 1, n, l, r);
			cout << ans << endl;
		}

		// //debug
		// display_tree(1, 1, n, 0);
		// cout << endl;

	}

	return 0;
}