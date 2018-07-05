/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;
typedef pair<int, int> ii;
typedef set<ii> sii;

vvi adj_list;
vvi closest;

void bfs(int source, int N, int smaint_n){
	vi visited(N, 0);
	vi distance(N, INT_MAX);
	queue<int> q;
	
	visited[source] = 1;
	distance[source] = 0;
	q.push(source);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nbour : adj_list[u]){
			if(visited[nbour] == 0){
				q.push(nbour);
				visited[nbour] = 1;
				distance[nbour] = distance[u] + 1;
			}
		}
	}

	for(int i = 0; i < smaint_n; i++){
		closest[i][source - smaint_n] = distance[i] - 1;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k, s;
	cin >> n >> m >> k >> s;

	vi a(n);
	vsi col_sets(k, si());
	for(int i = 0;	i < n; i++){
		cin >> a[i];
		a[i]--;
		col_sets[a[i]].insert(i);
	}

	int u, v;
	adj_list = vvi(n + k, vi());
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--;
		v--;
		adj_list[u].pb(v);
		adj_list[v].pb(u);
	}

	// int node_num = n;
	// for(int col = 0; col < k; col++){
	// 	// create dummy node for color col
	// 	for(si::iterator it = col_sets[col].begin(); it != col_sets[col].end(); it++){
	// 		adj_list[node_num].pb(*it);
	// 		adj_list[*it].pb(node_num);
	// 	}
	// 	node_num++;
	// }

	closest = vvi(n, vi(k, INT_MAX));
	for(int s = n; s < n + k; s++){
		// create dummy node for color col
		for(si::iterator it = col_sets[s - n].begin(); it != col_sets[s - n].end(); it++){
			adj_list[s].pb(*it);
			adj_list[*it].pb(s);
		}
		bfs(s, n + k, n);
		adj_list[s].clear();
		for(si::iterator it = col_sets[s - n].begin(); it != col_sets[s - n].end(); it++){
			adj_list[*it].pop_back();
		}
	}

	for(int i = 0; i < n; i++){
		// sii smaintest_dists;
		// for(int col = 0; col < k; col++){
		// 	smaintest_dists.insert(make_pair(closest[i][col], col));
		// 	// cout << i + 1 << " " << col + 1 << " " << closest[i][col] << endl;
		// }

		sort(closest[i].begin(), closest[i].end());
		int ans = 0;
		for(int col = 0; col < s; col++)
			ans += closest[i][col];
		// int taken = 0;
		// int ans = 0;
		// for(sii::iterator it = smaintest_dists.begin(); it != smaintest_dists.end() && taken < s; it++){
		// 	ans += (*it).first;
		// 	taken++;
		// }

		cout << ans << " ";
	}

	return 0;
}