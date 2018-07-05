/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
#define pb push_back

vvll adj_list;
vvll dp_num_paths;
int n, k;
vi visited;

void dfs_path(int s, int p){
	visited[s] = 1;
	for(int nbour : adj_list[s]){
		if(visited[nbour] == 0){
			dfs_path(nbour, s);
		}
	}

	dp_num_paths[s][0] = 1;
	for(int i = 1; i <= k; i++){
		for(int child : adj_list[s]){
			if(child == p)
				continue;
			dp_num_paths[s][i] += dp_num_paths[child][i - 1];
		}
	}
}

ll ans = 0;
void dfs_numpath(int s, int p){
	visited[s] = 1;
	for(int nbour : adj_list[s]){
		if(visited[nbour] == 0){
			dfs_numpath(nbour, s);
		}
	}
	
	int i;
	ans += dp_num_paths[s][k];
	for(i = 1; i < k - i; i++){
		ans += (dp_num_paths[s][i] * dp_num_paths[s][k - i]);
		for(int nbour : adj_list[s]){
			if(nbour == p)
				continue;
			ans -= (dp_num_paths[nbour][i - 1] * dp_num_paths[nbour][k - i - 1]);
		}
	}
	if(i == k - i){
		ans += ((dp_num_paths[s][i] - 1) * dp_num_paths[s][i]) / 2;
		for(int nbour : adj_list[s]){
			if(nbour == p)
				continue;
			ans -= (dp_num_paths[nbour][i - 1] * (dp_num_paths[nbour][i - 1] - 1)) / 2;
		}
	}
}

void show_dp(){
	for(int i = 1; i <= n; i++){
		cout << "node " << i << "->" << endl;
		for(int j = 0; j <= k; j++)
			cout << j << ":" << dp_num_paths[i][j] << " ";
		cout << endl;
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	adj_list = vvll(n + 1, vll());
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		adj_list[u].pb(v);
		adj_list[v].pb(u);
	}

	dp_num_paths = vvll(n + 1, vll(k + 1, 0));
	visited = vi(n + 1, 0);
	dfs_path(1, 1);

	//show_dp();

	visited = vi(n + 1, 0);
	dfs_numpath(1, 1);
	cout << ans;

	return 0;
}