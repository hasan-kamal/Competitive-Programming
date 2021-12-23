/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, bool> ib;
typedef vector<ib> vib;
typedef vector<vib> vvib;

vvib remove_edges(vvib &original_graph_adj, int d, vi &degree){
	set<int> nodes_selected = set<int>();
	int n = original_graph_adj.size();
	for(int i = 0; i < n; i++){
		if(degree[i] <= d)
			nodes_selected.insert(i);
	}

	// if(d == 2){
	// 	cout << "nodes selected at d=2" << endl;
	// 	for(int n : nodes_selected)
	// 		cout << "\t" << n << endl;
	// 	cout << endl;
	// }

	vvib copy_graph = vvib(original_graph_adj);
	for(int n : nodes_selected){
		for(ib &p : copy_graph[n]){
			p.second = false;

			for( ib &x : copy_graph[p.first]){
				if(x.first == n){
					x.second = false;
				}
			}

		}
	}
	return copy_graph;
}

void dfs_visit(int s, vi &visited, vvib &adj_list){
	visited[s] = 1;
	for(ib &nbour : adj_list[s]){
		if(nbour.second == true && visited[nbour.first] == 0){
			dfs_visit(nbour.first, visited, adj_list);
		}
	}
}

int count_components(vvib &graph_adj){
	int n = graph_adj.size();
	int num_components = 0;

	vi visited(n, 0);
	for(int i = 0; i < n; i++){
		if(visited[i] == 0){
			num_components++;
			dfs_visit(i, visited, graph_adj);
		}
	}

	return num_components;
}

int main(){

	int t;
	cin >> t;

	int n, m;
	while(t--){
		cin >> n >> m;
		vvib adj_list = vvib(n, vib());
		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			u--;
			v--;
			adj_list[u].push_back(make_pair(v, true));
			adj_list[v].push_back(make_pair(u, true));
		}

		for(int i = 0; i < n; i++){
			cout << i << " -> ";
			for(ib &nbour : adj_list[i])
				cout << nbour.first << " ";
			cout << endl;
		}

		vi degree = vi(n);
		for(int i = 0; i < n; i++){
			degree[i] = adj_list[i].size();
		}

		for(int d = 0; d < n; d++){

			vvib new_graph = remove_edges(adj_list, d, degree);
			int num_connected_components = count_components(new_graph);

			if(d == 2 || d == 0){
				//cout << "at d = " << d << " num_components=" << num_connected_components << endl;
			}

			cout << num_connected_components -1 << " ";
		}
		cout << endl;
	}

	return 0;
}