#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef vector<vi> vvi;

vi color;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int u, v;
	vvi adj_list(n);
	vector< pair<int, int> > edges;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		u--;
		v--;
		edges.push_back(make_pair(u, v));
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	color = vi(n, -1);

	queue<int> q;
	q.push(0);
	color[0] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nbour : adj_list[u]){
			if(color[nbour] == -1){
				color[nbour] = 1 - color[u];
				q.push(nbour);
			}else if(color[nbour] == color[u]){
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for(pair<int, int> edge : edges){
		if(color[edge.first] == 0)
			cout << 0;
		else
			cout << 1;
	}

	return 0;
}