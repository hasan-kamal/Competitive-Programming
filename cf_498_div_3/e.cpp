#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi adj_list;
vi num_children;
vi order;
map<int, int> u_to_pos;
vi num_in_list;

int dfs(int source, int count){
	order[count] = source;
	u_to_pos[source] = count;
	int num_children = 0;

	for(int nbour : adj_list[source]){
		num_children++;
		num_children += dfs(nbour, count + num_children);
	}

	num_in_list[source] = num_children + 1;
	return num_children;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;

	int p;
	adj_list = vvi(n, vi());
	for(int i = 1; i < n; i++){
		cin >> p;
		p--;
		adj_list[p].push_back(i);
	}

	for(int i = 0; i < n; i++){
		sort(adj_list[i].begin(), adj_list[i].end());
	}

	order = vi(n);
	num_in_list = vi(n);
	u_to_pos = map<int, int>();
	dfs(0, 0);

	int u, k;
	while(q--){
		cin >> u >> k;
		u--;
		if(k > num_in_list[u])
			cout << -1 << endl;
		else
			cout << order[u_to_pos[u] + k - 1] + 1 << endl;
	}

	return 0;
}