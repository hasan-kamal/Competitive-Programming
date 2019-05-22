#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int	ll;
typedef pair<int, int> 	ii;
typedef vector<ii> 		vii;
typedef vector<vii>		vvii;

void dfs(vvii &adj_list, int s, vi &color){
	for(ii nbour : adj_list[s]){
		if(color[nbour.first] == -1){
			if(nbour.second % 2 == 0)
				color[nbour.first] = color[s];
			else
				color[nbour.first] = 1 - color[s];
			dfs(adj_list, nbour.first, color);
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vvii adj_list(n, vii());
	int u, v, w;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v >> w;
		adj_list[u - 1].push_back(make_pair(v - 1, w));
		adj_list[v - 1].push_back(make_pair(u - 1, w));
	}

	vi color(n, -1);
	color[0] = 0;
	dfs(adj_list, 0, color);
	for(int i = 0; i < n; i++)
		cout << color[i] << endl;

	return 0;
}