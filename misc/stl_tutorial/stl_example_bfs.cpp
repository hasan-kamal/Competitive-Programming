/*

@author Hasan Kamal

*/

//also demonstrates usage of queue

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef vector<vector<int> > vvi;
typedef vector<int> vi;

void disp_map(map<int, int> &m){
	// vector<pair<int, int> > v(m.begin(), m.end());
	// for(pair<int, int> x : v)
	// 	cout<<"node "<<x.first<<" at distance "<<x.second<<endl;
	for(map<int, int>::iterator it = m.begin(); it!=m.end(); it++)
		cout<<"node "<<it->first<<" at distance "<<it->second<<endl; 
}

void bfs(vvi &list, int source){

	vi visited(int(list.size()), 0);
	vi dist(int(list.size()), -1);

	queue<int> q;
	q.push(source);
	visited[source] = 1;
	dist[source] = 0;

	while(!q.empty()){
		int t = q.front();
		q.pop();

		for(auto nbour : list[t])
			if(!visited[nbour]){
				q.push(nbour);
				visited[nbour] = 1;
				dist[nbour] = dist[t] + 1;
			}
	}

	//show (node,distance) pairing
	map<int, int> m;
	int n = int(list.size());
	for(int i=0; i<n; i++)
		m[i] = dist[i];
	disp_map(m);
}

int main(){

	int n;
	cin>>n;

	vvi adj_list(n);

	int e, i, u, v;
	cin>>e;
	for(i=0; i<e; i++){
		cin>>u>>v;//assuming numbered [0,n-1]
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	bfs(adj_list, 0);

	return 0;
}