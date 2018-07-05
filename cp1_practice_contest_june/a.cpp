/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef set<ll> si;
typedef queue<ll> qi;
vvi adj_list;

bool graph_bipartite(ll n, si &a, si &b){

	vi visited(n + 1, 0);
	qi q;
	vi color = vi(n + 1, -1);

	for(int x = 1; x <= n; x++){
		
		if(visited[x] == 0){
			q = qi();
			q.push(x);
			visited[x] = 1;
			color[x] = 0;
			a.insert(x);
		}

		while(!q.empty()){
			
			ll u = q.front();
			q.pop();

			for(ll nbour : adj_list[u]){
				if(visited[nbour] == 0){
					q.push(nbour);
					visited[nbour] = 1;
					color[nbour] = 1 - color[u];
					if(color[nbour] == 0)
						a.insert(nbour);
					else
						b.insert(nbour);
				}else{
					if(color[nbour] == color[u])
						return false;
				}
			}

		}

	}

	return true;
}

int main(){

	ll n, m;
	cin >> n >> m;

	adj_list = vvi(n + 1, vi());
	ll u, v;
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	si a = si();
	si b = si();
	if(graph_bipartite(n, a, b)){

		cout << a.size() << endl;
		for(si::iterator it = a.begin(); it != a.end(); it++){
			cout << *it << " ";
		}
		cout << endl;

		cout << b.size() << endl;
		for(si::iterator it = b.begin(); it != b.end(); it++){
			cout << *it << " ";
		}


	}else{
		cout << "-1";
	}

	return 0;
}