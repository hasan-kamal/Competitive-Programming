/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef set<ll> si;
typedef vector<si> vsi;
typedef pair<ll, ll> ii;
typedef set<ii> sii;

vvi adj_list;
vvi closest;

void bfs(ll source, ll N, ll small_n){
	vi visited(N, 0);
	vi distance(N, LONG_MAX);
	queue<ll> q;
	
	visited[source] = 1;
	distance[source] = 0;
	q.push(source);

	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(ll nbour : adj_list[u]){
			if(visited[nbour] == 0){
				q.push(nbour);
				visited[nbour] = 1;
				distance[nbour] = distance[u] + 1;
			}
		}
	}

	for(ll i = 0; i < small_n; i++){
		closest[i][source - small_n] = distance[i] - 1;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, k, s;
	cin >> n >> m >> k >> s;

	vi a(n);
	vsi col_sets(k, si());
	si colors_seen;
	map<int, int> col_to_ind;
	int num_col = 0;
	for(ll i = 0;	i < n; i++){
		cin >> a[i];
		a[i]--;
		if(colors_seen.find(a[i]) == colors_seen.end()){
			colors_seen.insert(a[i]);
			col_to_ind[a[i]] = num_col;
			col_sets[num_col].insert(i);
			num_col++;
		}else{
			col_sets[col_to_ind[a[i]]].insert(i);
		}
	}
	k = num_col;

	ll u, v;
	adj_list = vvi(n + k, vi());
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		u--;
		v--;
		adj_list[u].pb(v);
		adj_list[v].pb(u);
	}

	ll node_num = n;
	for(ll col = 0; col < k; col++){
		// create dummy node for color col
		for(si::iterator it = col_sets[col].begin(); it != col_sets[col].end(); it++){
			adj_list[node_num].pb(*it);
			adj_list[*it].pb(node_num);
		}
		node_num++;
	}

	closest = vvi(n, vi(k, LONG_MAX));
	for(ll s = n; s < n + k; s++){
		bfs(s, n + k, n);
	}

	for(ll i = 0; i < n; i++){
		sort(closest[i].begin(), closest[i].end());
		ll ans = 0;
		for(ll dis = 0; dis < s; dis++)
			ans += closest[i][dis];
		cout << ans << " ";
	}

	return 0;
}