/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef set<ii> sii;

void bfs(vvi &adj_list, int n, vi &level){
	queue<int> q;
	vi visited(n);
	
	visited[0] = 1;
	q.push(0);
	level[0] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int nbour : adj_list[u]){
			if(!visited[nbour]){
				q.push(nbour);
				level[nbour] = level[u] + 1;
				visited[nbour] = 1;
			}
		}
	}
}

bool dfs_visit_cycle(vvi &adj_list, int n, vi &visited, int s){
	visited[s] = 1;

	for(int nbour : adj_list[s]){
		if(visited[nbour]==0){
			return dfs_visit_cycle(adj_list, n, visited, nbour);
		}else if(visited[nbour]==1)
			return true;
	}

	visited[s] = 2;
	return false;
}

bool dfs_cycle(vvi &adj_list, int n){
	vi visited(n, 0);

	for(int i=0; i<n; i++){
		if(visited[i]==0){
			if(dfs_visit_cycle(adj_list, n, visited, i))
				return true;
		}
	}

	return false;
}

int main(){

	int t;
	cin>>t;

	int n, m, u, v;
	while(t--){
		cin>>n>>m;

		vvi adj_list(n);
		sii edges;
		for(int i=0; i<m; i++){
			cin>>u>>v;
			u--;
			v--;
			adj_list[u].pb(v);
			adj_list[v].pb(u);
			edges.insert(make_pair(u, v));
		}

		vi p(n);
		for(int i=1; i<n; i++){
			cin>>p[i];
			p[i]--;
		}

		vi level(n);
		bfs(adj_list, n, level);

		bool flag = true;
		for(int i=1; i<n; i++){
			if(abs(level[i]-level[p[i]])!=1){
				flag = false;
				break;
			}
		}

		if(!flag){
			cout<<"NO"<<endl;
			continue;
		}

		vvi g_prime(n);
		for(const ii &edge : edges){
			int u = edge.first;
			int v = edge.second;
			
			if(p[u]==v || p[v]==u){
				continue;
			}else{
				//edge not in T
				if(level[u]>level[v]){
					
					g_prime[p[u]].pb(v);
					int x = p[u];
					int y = v;
					while(p[x]!=p[y]){
						g_prime[p[x]].pb(p[y]);
						x = p[x];
						y = p[y];
					}

				}else{

					g_prime[p[v]].pb(u);
					int x = p[v];
					int y = u;
					while(p[x]!=p[y]){
						g_prime[p[x]].pb(p[y]);
						x = p[x];
						y = p[y];
					}

				}
				
			}
		}

		// for(int i=0; i<n; i++){
		// 	for(int nbour : g_prime[i]){
		// 		cout<<i<<"->"<<nbour<<endl;
		// 	}
		// 	cout<<endl;
		// }

		if(dfs_cycle(g_prime, n))
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}

	return 0;
}