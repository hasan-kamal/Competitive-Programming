/*

@author Hasan Kamal

*/

#include <iostream>
#include <queue>
using namespace std;

#define N 501
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

bool valid(int i, int j, int n, int m){
	if(i >= 0 && i < n && j >= 0 && j < m)
		return trcue;
	return false;
}

int bfs(vvii &adj_list, int n, int m, int start_index){
	queue<int> q;
	vi visited(n * m + 1, 0);
	vi distance(n * m + 1, 0);

	q.push(start_index);
	visited[start_index] = 1;
	distance[start_index] = 0;

	int depth = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(ii &nbour : adj_list[u]){
			if(visited[nbour.first] == 0){
				visited[nbour.first] = 1;
				distance[nbour.first] = distance[u] + 1;
				
				if(distance[nbour.first] > depth)
					depth = distance[nbour.first];

				q.push(nbour.first);
			}
		}
	}

	return depth;
}

void disp(vvii &adj_list, int n, int m){
	cout << "displaying adjacency list" << endl;
	for(int i = 0; i < n * m + 1; i++){
		cout << i << " -> ";
		for(ii &nbour : adj_list[i])
			cout << nbour.first << ", ";
		cout << endl;
	}
	cout << endl;
}

int main(){

	int t;
	cin >> t;

	int a[N][N];
	while(t--){

		int n, m;
		cin >> n >> m;

		int max_val = -1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
				if(a[i][j] > max_val)
					max_val = a[i][j];
			}
		}

		//make graph
		vii max_cells = vii();
		vvii adj_list = vvii(n * m + 1, vii());
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){

				if(a[i][j] == max_val)
					max_cells.push_back(make_pair(i, j));

				int id = i * m + j;

				if(valid(i-1, j-1, n, m))
					adj_list[id].push_back(make_pair((i-1)*m + j-1, a[i-1][j-1]));
				if(valid(i-1, j, n, m))
					adj_list[id].push_back(make_pair((i-1)*m + j, a[i-1][j]));
				if(valid(i-1, j+1, n, m))
					adj_list[id].push_back(make_pair((i-1)*m + j+1, a[i-1][j+1]));
				if(valid(i, j-1, n, m))
					adj_list[id].push_back(make_pair(i*m + j-1, a[i][j-1]));
				if(valid(i, j+1, n, m))
					adj_list[id].push_back(make_pair(i*m + j+1, a[i][j+1]));
				if(valid(i+1, j-1, n, m))
					adj_list[id].push_back(make_pair((i+1)*m + j-1, a[i+1][j-1]));
				if(valid(i+1, j, n, m))
					adj_list[id].push_back(make_pair((i+1)*m + j, a[i+1][j]));
				if(valid(i+1, j+1, n, m))
					adj_list[id].push_back(make_pair((i+1)*m + j+1, a[i+1][j+1]));


			}
		}

		//cout << "num max cells = " << max_cells.size() << endl;

		int dummy_node_index = m * n;
		for(ii &p : max_cells){
			adj_list[dummy_node_index].push_back(make_pair(p.first * m + p.second, a[p.first][p.second]));
		}

		//disp(adj_list, n, m);

		int depth_tree = bfs(adj_list, n, m, dummy_node_index);
		cout << depth_tree - 1 << endl;
	}	
	
	return 0;
}