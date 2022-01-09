/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define A 1000001
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void factorise(vi &a, vvi &factorisation, int n){

	vi first_prime_factor = vi(A, -1);

	//sieve of eratosthenes
	vi is_prime = vi(A, 1);
	is_prime[0] = is_prime[1] = 0;
	for(int i = 2; i * i < A; i++){
		for(int j = i * i; j < A; j += i){
			if(first_prime_factor[j] == -1)
				first_prime_factor[j] = i;
			is_prime[j] = 0;
		}
	}

	vi primes = vi();
	for(int i = 2; i < A; i++){
		if(is_prime[i]){
			first_prime_factor[i] = i;
			primes.push_back(i);
		}
	}

	//create factorisation of given numbers
	for(int i = 0; i < n; i++){
		int val = a[i];
		while(val > 1){
			factorisation[i].push_back(first_prime_factor[val]);
			val /= first_prime_factor[val];
		}
	}

}

vvi tree;
vvi factorisation;

void build_segtree(int id, int start, int end){

	if(start == end){
		tree[id] = factorisation[start - 1];
		return;
	}

	int mid = start + (end - start) / 2;

	//recurse and build sub-tree
	build_segtree(2 * id, start, mid);
	build_segtree(2 * id + 1, mid + 1, end);

	vi &left_fact = tree[2 * id];
	vi &right_fact = tree[2 * id + 1];

	int SENTINEL = INT_MAX;
	left_fact.push_back(SENTINEL);
	right_fact.push_back(SENTINEL);

	int x1 = 0, x2 = 0;
	while(left_fact[x1] != SENTINEL || right_fact[x2]!=SENTINEL){
		if(left_fact[x1] < right_fact[x2]){
			tree[id].push_back(left_fact[x1]);
			x1++;
		}else{
			tree[id].push_back(right_fact[x2]);
			x2++;
		}
	}

	left_fact.pop_back();
	right_fact.pop_back();
}

int query_segtree(int id, int start, int end, int l, int r, int x, int y){

	//not intersecting at all
	if(r < start || l > end){
		return 0;
	}

	//if interval of this node lies completely inside the range
	if(l <= start && end <= r){
		//binary search
		return upper_bound(tree[id].begin(), tree[id].end(), y) - upper_bound(tree[id].begin(), tree[id].end(), x - 1);
	}

	//if only partially intersects
	int mid = start + (end - start) / 2;
	return query_segtree(2 * id, start, mid, l, r, x, y) + query_segtree(2 * id + 1, mid + 1, end, l, r, x, y);

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	factorisation = vvi(n, vi());
	factorise(a, factorisation, n);
	tree = vvi(4 * n, vi());
	build_segtree(1, 1, n);

	int q;
	cin >> q;

	int l, r, x, y;
	while(q--){
		cin >> l >> r >> x >> y;
		cout << query_segtree(1, 1, n, l, r, x, y) << endl;
	}

	return 0;
}