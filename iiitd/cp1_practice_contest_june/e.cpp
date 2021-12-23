/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>
#define INFINITY 1000000
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef queue<int> qi;
vvi g, g_transpose;

vi visited;
bool dfs_reachable(int s, si &locations, vvi &g, int n){
	visited[s] = 1;
	if(locations.find(s) != locations.end())
		return true;

	for(int nbour : g[s]){
		if(visited[nbour] == 0){
			if(dfs_reachable(nbour, locations, g, n))
				return true;
		}
	}

	return false;
}

void bfs(int s, vi &dist, vvi &adj_list, int n){
	
	qi q = qi();
	vi visited = vi(n + 1, 0);

	dist[s] = 0;
	visited[s] = 1;
	q.push(s);

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nbour : adj_list[u]){
			if(visited[nbour] == 0){
				visited[nbour] = 1;
				dist[nbour] = dist[u] + 1;
				q.push(nbour);
			}
		}
	}

}

void disp(vi &a, int start, int end){
	for(int i = start; i <= end; i++){
		cout << i << ")" << a[i] << " ";
	}
	cout << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vi iron_loc = vi(m);
	si iron_loc_set = si();
	for(int i = 0; i < m; i++){
		cin >> iron_loc[i];
		iron_loc_set.insert(iron_loc[i]);
	}

	vi coal_loc = vi(k);
	si coal_loc_set = si();
	for(int i = 0; i < k; i++){
		cin >> coal_loc[i];
		coal_loc_set.insert(coal_loc[i]);
	}

	g = vvi(n + 1, vi());
	g_transpose = vvi(n + 3, vi());

	int num_nbour, nbour;
	for(int i = 1; i <= n; i++){
		cin >> num_nbour;
		while(num_nbour--){
			cin >> nbour;
			g[i].push_back(nbour);
			g_transpose[nbour].push_back(i);
		}
	}

	int iron_dummy_node_index = n + 1;
	int coal_dummy_node_index = n + 2;
	for(int i = 0; i < m; i++){
		g_transpose[iron_dummy_node_index].push_back(iron_loc[i]);
	}
	for(int i = 0; i < k; i++){
		g_transpose[coal_dummy_node_index].push_back(coal_loc[i]);
	}

	visited = vi(n + 1, 0);
	bool iron_reachable = dfs_reachable(1, iron_loc_set, g, n);
	visited = vi(n + 1, 0);
	bool coal_reachable = dfs_reachable(1, coal_loc_set, g, n);
	if(iron_reachable==false || coal_reachable==false){
		cout << "impossible";
		return 0;
	}

	vi dist_from_s = vi(n + 1, INFINITY);
	bfs(1, dist_from_s, g, n);

	vi dist_from_iron = vi(n + 3, INFINITY);
	bfs(iron_dummy_node_index, dist_from_iron, g_transpose, n + 2);

	vi dist_from_coal = vi(n + 3, INFINITY);
	bfs(coal_dummy_node_index, dist_from_coal, g_transpose, n + 2);

	// cout << "dist_from_s" << endl;
	// disp(dist_from_s, 1, n);
	// cout << "dist_from_iron" << endl;
	// disp(dist_from_iron, 1, n + 2);
	// cout << "dist_from_coal" << endl;
	// disp(dist_from_coal, 1, n + 2);

	int min = INT_MAX;
	int length;
	for(int v = 1; v <= n; v++){
		length = dist_from_s[v] + (dist_from_iron[v] - 1) + (dist_from_coal[v] - 1);
		if(length < min)
			min = length;
	}
	cout << min;

	return 0;
}