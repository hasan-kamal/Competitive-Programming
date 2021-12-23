/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
vvi adj_list;
vi end_nodes;
vi visited;

void dfs_visit(int s){
	visited[s] = 1;
	for(int nbour : adj_list[s]){
		if(visited[nbour] == 0)
			dfs_visit(nbour);
	}
	if(adj_list[s].size() == 1)
		end_nodes.pb(s);
}

void dfs(int source){
	int n = adj_list.size();
	visited = vi(n, 0);
	
	dfs_visit(source);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi nodes_degree_one;

	int a, b;
	adj_list = vvi(n, vi());
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--;
		b--;
		adj_list[a].pb(b);
		adj_list[b].pb(a);
	}

	int deg_greater_two = 0;
	int deg_two = 0;
	int special_node;
	for(int i = 0; i < n; i++){
		if(adj_list[i].size() > 2){
			deg_greater_two++;
			special_node = i;
		}else if(adj_list[i].size() == 2){
			deg_two++;
		}else if(adj_list[i].size() == 1){
			nodes_degree_one.pb(i);
		}
	}

	if(deg_greater_two > 1){
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;

	if(deg_greater_two == 1){
		cout << adj_list[special_node].size() << endl;
		// dfs(special_node);
		for(int end : nodes_degree_one)
			cout << special_node + 1 << " " << end + 1 << endl;
	}else{
		cout << 1 << endl;
		// dfs(special_node);
		// for(int end : nodes_degree_one)
		// 	cout << special_node + 1 << " " << end + 1 << endl;
		cout << nodes_degree_one[0] + 1 << " " << nodes_degree_one[1] + 1 << endl;
	} 
	

	return 0;
}