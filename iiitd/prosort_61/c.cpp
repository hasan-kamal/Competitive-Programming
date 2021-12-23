/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi ans;
vi scc;
vi min_scc;
vi k;

int minimum(int x, int y){
	return x < y ? x : y;
}

int tme;
void dfs(vvi &adj_list, int s, vi &visited, vii &finish){
	visited[s] = 1;
	for(int nbour : adj_list[s]){
		if(visited[nbour] == 0)
			dfs(adj_list, nbour, visited, finish);
	}
	finish[s] = make_pair(tme, s);
	tme++;
}

void dfs_new(vvi &adj_list_t, int s, vi &visited, int cc){
	visited[s] = 1;
	scc[s] = cc;
	if(min_scc[cc] > k[s])
		min_scc[cc] = k[s];
	for(int nbour : adj_list_t[s]){
		if(visited[nbour] == 0)
			dfs_new(adj_list_t, nbour, visited, cc);
	}
}

void dfs_final(vvi &adj_list, int s, vi &visited){
	visited[s] = 1;
	for(int nbour : adj_list[s]){
		if(visited[nbour] == 0){
			dfs_final(adj_list, nbour, visited);
			ans[scc[s]] = minimum(ans[scc[s]], ans[scc[nbour]]);
		}
	}
}

void solve(vvi &adj_list, int n, int m){
	vi visited(n, 0);
	vii finish(n, make_pair(-1, -1));
	tme = 0;
	for(int i = 0; i < n; i++){
		if(visited[i] == 0)
			dfs(adj_list, i, visited, finish);
	}

	vvi adj_list_t(n);
	for(int i = 0; i < n; i++){
		for(int nbour : adj_list[i])
			adj_list[nbour].pb(i);
	}
	
	sort(finish.rbegin(), finish.rend());
	// for(ii x : finish){
	// 	cout << x.second  + 1<< endl;
	// }

	visited = vi(n, 0);
	int cc = 0;
	for(ii x : finish){
		if(visited[x.second] == 0){
			dfs_new(adj_list_t, x.second, visited, cc);
			cc++;
		}
	}

	for(int i = 0; i < n; i++){
		vi l;
		for(int j = 0; j < n; j++)
			if(scc[j] == i)
				l.pb(j);
		// cout << "scc " << i << " has following: min_scc=" << min_scc[i] << endl;
		// for(int x : l)
		// 	cout << x + 1 << endl;
		// cout << endl;
	}

	visited = vi(n, 0);
	ans = min_scc;
	for(ii x : finish){
		if(visited[x.second] == 0){
			dfs_final(adj_list, x.second, visited);
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		k = vi(n);
		for(int i = 0; i < n; i++)
			cin >> k[i];

		int m;
		cin >> m;

		vvi adj_list(n);
		for(int i = 0; i < m; i++){
			int x, y;
			cin >> x >> y;
			x--; y--;
			// adj_list[x].pb(y);
			adj_list[y].pb(x);
		}

		ans = vi(n, INT_MAX);
		scc = vi(n, -1);
		min_scc = vi(n, INT_MAX);
		solve(adj_list, n, m);

		int q;
		cin >> q;
		while(q--){
			int a;
			cin >> a;
			a--;
			cout << ((ans[scc[a]] == INT_MAX) ? -1 : ans[scc[a]]) << endl;
		}
	}

	return 0;
}