/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;

vvi adj_list;
vi height;

void preprocess_heights(int s, int h){
	height[s] = h;
	for(int nbour : adj_list[s]){
		if(height[nbour] < 0){
			preprocess_heights(nbour, h + 1);
		}
	}
}

vi tour;
vi visited_tour;
int discovery_time;
vi d_time;
void do_tour(int s){
	tour[discovery_time] = s;
	visited_tour[s] = 1;
	if(d_time[s] < 0){
		d_time[s] = discovery_time;
	}
	for(int nbour : adj_list[s]){
		if(visited_tour[nbour] == 0){
			discovery_time++;
			do_tour(nbour);

			discovery_time++;
			tour[discovery_time] = s;
		}
	}
}

void show_tour(int n){
	for(int i = 0; i <= n + n - 1; i++)
		cout << "t=" << i << " node=" << tour[i] << endl;
	for(int i = 1; i <= n; i++)
		cout << "node " << i << " first discovered at time t=" << d_time[i] << endl;
}

int maximum(int a, int b){
	return a > b ? a : b;
}

int minimum(int a, int b){
	return a < b ? a : b;
}

int lca_brute(int a, int b){
	//return the node with minimum height in range [d_time[a], d_time[b]] of tour array
	int low = minimum(d_time[a], d_time[b]);
	int hi = maximum(d_time[a], d_time[b]);
	
	int ans = tour[low];
	for(int i = low; i <= hi; i++){
		if(height[tour[i]] < height[ans])
			ans = tour[i];
	}
	return ans;
}

vi segtree;
void build_tree(int v, int start, int end){
	if(start == end){
		segtree[v] = tour[start];
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	if(height[segtree[2 * v]] < height[segtree[2 * v + 1]])
		segtree[v] = segtree[2 * v];
	else
		segtree[v] = segtree[2 * v + 1];
}

int query_tree(int v, int start, int end, int l, int r){
	if(start == l && end == r){
		return segtree[v];
	}

	int mid = start + (end - start) / 2;
	if(r <= mid)
		return query_tree(2 * v, start, mid, l, r);
	else if(mid < l)
		return query_tree(2 * v + 1, mid + 1, end, l, r);

	int l_ans = query_tree(2 * v, start, mid, l, mid);
	int r_ans = query_tree(2 * v + 1, mid + 1, end, mid + 1, r);
	if(height[l_ans] < height[r_ans])
		return l_ans;
	else
		return r_ans;
}

int lca_fast(int a, int b, int n){
	int t_low = minimum(d_time[a], d_time[b]);
	int t_hi = maximum(d_time[a], d_time[b]);
	return query_tree(1, 0, n + n - 2, t_low, t_hi);
}

int dist(int a, int b, int n){
	int lca = lca_fast(a, b, n);
	//cout << "lca of " << a << ", " << b << " is " << lca << endl;
	return height[a] - height[lca] + height[b] - height[lca];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	adj_list = vvi(n + 1, vi());
	int u;
	for(int i = 2; i <= n; i++){
		cin >> u;
		adj_list[u].pb(i);
		adj_list[i].pb(u);
	}

	height = vi(n + 1, -1);
	preprocess_heights(1, 0);

	tour = vi(n + n, -1);
	d_time = vi(n + 1, -1);
	visited_tour = vi(n + 1, 0);
	discovery_time = 0;
	do_tour(1);

	//show_tour(n);

	segtree = vi(4 * (2 * n - 1), -1);
	build_tree(1, 0, n + n - 2);

	vi inp = vi(3);
	int ans;
	while(q--){
		cin >> inp[0] >> inp[1] >> inp[2];
		
		ans = 0;
		sort(inp.begin(), inp.end());
		do{
			int s = inp[0];
			int f = inp[1];
			int t = inp[2];
			ans = maximum(ans, (dist(s, f, n) + dist(t, f, n) - dist(s, t, n) + 1) / 2);
		}while(next_permutation(inp.begin(), inp.end()));

		cout << ans + 1 << endl;
	}

	return 0;
}