/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

void dfs_visit(vector<vector<int> > &l, int source, vector<bool> &visited){
	visited[source] = true;
	for(int nbour : l[source])
		if(!visited[nbour])
			dfs_visit(l, nbour, visited);
}

bool dfs(vector<vector<int> > &l){
	vector<bool> visited(int(l.size()), false);
	int n = int(l.size());

	bool is_connected = true;
	dfs_visit(l, 0, visited);

	for(int i=1; i<n; i++){
		if(!visited[i]){
			is_connected = false;
			dfs_visit(l, i, visited);
		}
	}

	return is_connected;
}

int main(){

	int n;
	cin>>n;
	vector<vector<int> > adj_list(n);

	int e, i, u, v;
	cin>>e;
	for(i=0; i<e; i++){
		cin>>u>>v; //assuming nodes are numbered [0, n-1]
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	if(dfs(adj_list))
		cout<<"connected graph"<<endl;
	else
		cout<<"disconnected graph"<<endl;

	return 0;
}