#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int	ll;

void dfs(vvi &adj_list, int s, vi &color){
	color[s] = 1;
	for(int nbour : adj_list[s]){
		if(!color[nbour])
			dfs(adj_list, nbour, color);
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vvi adj_list(n, vi());
	int x, y, z;
	for(int i = 0; i < m; i++){
		cin >> x >> y >> z;
		adj_list[x - 1].push_back(y - 1);
		adj_list[y - 1].push_back(x - 1);
	}

	vi color(n, 0);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(!color[i]){
			dfs(adj_list, i, color);
			ans++;
		}
	}
	cout << ans;

	return 0;
}