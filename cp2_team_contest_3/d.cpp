/*

@author hasankamal

*/

#define mp make_pair
#define pb push_back

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef set<int> si;

si good = si();
int n;
vvii adj_list;

void bfs(int source){
	queue<int> q;
	q.push(source);

	vi visited(n, 0);
	visited[source] = 1;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nbour : adj_list[u]){
			if(!visited[nbour]){
				q.push(nbour);
				visited[nbour] = 1;
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	adj_list(n, vii());

	int a, b, c;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b >> c;
		a--;
		b--;
		adj_list[a].pb(mp(b, c));
		adj_list[b].pb(mp(a, c));
	}

	bfs(1);

	cout << good.size() << endl;
	for(si::iterator it = good.begin(); it != good.end(); it++){
		cout << *it << endl;
	}

	return 0;
}