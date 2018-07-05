/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi visited;

void dfs_visit(vvi &adj_list, ll source){
	visited[source] = 1;
	for(auto nbour : adj_list[source]){
		if(visited[nbour]==0)
			dfs_visit(adj_list, nbour);
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m, u, v;
	cin>>n>>m;
	
	ll repeat = 0;
	vvi adj_list(n);
	vi deg(n, 0);
	for(ll i=0; i<m; i++){
		cin>>u>>v;
		u--;
		v--;
		adj_list[u].push_back(v);
		deg[u]++;
		if(u!=v){
			adj_list[v].push_back(u);
			deg[v]++;
		}else{
			repeat++;
		}
	}

	ll s_deg=0;
	for(ll i=0; i<n; i++){
		if(deg[i]>0){
			s_deg=i;
			break;
		}
	}

	visited = vi(n, 0);
	dfs_visit(adj_list, s_deg);

	for(ll i=0; i<n; i++){
		if(visited[i]==0 && deg[i]>0){
			cout<<0;
			return 0;
		}
	}

	ll ans=0;
	for(ll i=0; i<n; i++){
		if(deg[i]>1){
			ans = ans + ( (deg[i]*(deg[i]-1))/2 );
		}
	}
	ans=ans+( (repeat*(repeat-1))/2 );
	cout<<ans;

	return 0;
}