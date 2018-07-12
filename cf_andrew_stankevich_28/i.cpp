/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;

ll minimum(ll a, ll b){
	return a < b ? a : b;
}

vi visited;
vi low;
vi num_children;
vll ans;
vi discovery;

int n;
vvi adj_list;

int tme = 0;

void dfs(int source, int parent){

	// cout << "order " << source + 1 << "::" << endl;

	tme++;
	visited[source] = 1;
	discovery[source] = tme;
	num_children[source] = 1;

	vi art_sets;
	int sum_art_sets = 0;

	int smallest_low = tme;
	bool is_articulation = false;
	for(int nbour : adj_list[source]){
		if(visited[nbour] == 0){
			dfs(nbour, source);
			smallest_low = minimum(smallest_low, low[nbour]);
			num_children[source] += num_children[nbour];

			if(low[nbour] >= discovery[source]){
				art_sets.pb(num_children[nbour]);
				sum_art_sets += num_children[nbour];
				is_articulation = true;
			}

		}else{
			// back edge
			if(nbour != parent)
				smallest_low = minimum(smallest_low, discovery[nbour]);
		}
	}

	if(is_articulation){
		art_sets.pb(n - sum_art_sets - 1);
		int sz = art_sets.size();
		for(int i = 0; i < sz; i++){
			for(int j = i + 1; j < sz; j++)
				ans[source] += art_sets[i] * art_sets[j];
		}
	}

	// cout << endl;
	// cout << "art_sets for " << source + 1 << endl;
	// for(int v : art_sets)
	// 	cout << v << endl;
	// cout << endl;

	low[source] = smallest_low;
}

int main(){

	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> n >> m;

	int u, v;
	adj_list = vvi(n, vi());
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--;
		v--;
		adj_list[u].pb(v);
		adj_list[v].pb(u);
	}

	visited = vi(n, 0);
	low = vi(n, INT_MAX);
	num_children = vi(n, 0);
	ans = vll(n, 0);
	discovery = vi(n, 0);
	dfs(0, -1);

	for(ll v : ans)
		cout << v + n - 1 << endl;

	// cout << "num_children" << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << i + 1 << " has num_children=" << num_children[i] << endl;
	// }

	// cout << "low" << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << i + 1 << " has low=" << low[i] << endl;
	// }
	
	return 0;
}