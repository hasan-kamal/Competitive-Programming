#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n, m;
	while(t--){
		cin >> n >> m;
		vvi adj_list(n, vi());
		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			u--;
			v--;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}
		vi dist(n, INT_MAX);
		dist[0] = 0;
		queue<int> q;
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int nbour : adj_list[u]){
				if(dist[nbour] == INT_MAX){
					dist[nbour] = dist[u] + 1;
					q.push(nbour);
				}
			}
		}

		si even, odd;
		for(int i = 0; i < n; i++){
			if(dist[i] % 2 == 0)
				even.insert(i);
			else
				odd.insert(i);
		}

		if(even.size() <= odd.size()){
			cout << even.size() << endl;
			for(si::iterator it = even.begin(); it != even.end(); it++)
				cout << (*it) + 1 << " ";
			cout << endl;
		}else{
			cout << odd.size() << endl;
			for(si::iterator it = odd.begin(); it != odd.end(); it++)
				cout << (*it) + 1 << " ";
			cout << endl;
		}
	}		

	return 0;
}