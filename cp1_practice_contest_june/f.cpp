/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
vvi adj_list;
vi visited;

void dfs_visit(int s){
	visited[s] = 1;
	for(int nbour : adj_list[s]){
		if(visited[nbour] == 0)
			dfs_visit(nbour);
	}
}

int dfs(int n){
	visited = vi(n + 1, 0);
	int num_components = 0;

	for(int i = 1; i <= n; i++){
		if(visited[i] == 0){
			dfs_visit(i);
			num_components++;
		}
	}

	return num_components;
}

int main(){

	int n, m;
	cin >> n >> m;

	adj_list = vvi(n + 1, vi());
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	int num_components = dfs(n);

	cout << num_components;

	return 0;
}