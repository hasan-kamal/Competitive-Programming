/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef pair<int, int> ii;
typedef set<ii> sii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
vvii adj_list;
vi dest;
vi parent;

void djikstra_biased(int s, int g, int h, int n){
	
	//init
	for(int i = 1; i <= n; i++)
		parent[i] = -1;

	const int infinity = 5e7 + 1;
	vi dist = vi(n + 1, infinity);

	sii q = sii();
	for(int i = 1; i <= n; i++){
		q.insert(make_pair(dist[i], i));
	}

	//push source
	dist[s] = 0;
	q.erase(make_pair(infinity, s));
	q.insert(make_pair(0, s));

	while(!q.empty()){
		ii minp = *q.begin();
		q.erase(minp);
		int u = minp.second;
		for(ii nbourp : adj_list[u]){
			//relax
			int nbour = nbourp.first;
			int w = nbourp.second;
			if(dist[nbour] > dist[u] + w){
				q.erase(make_pair(dist[nbour], nbour));
				dist[nbour] = dist[u] + w;
				q.insert(make_pair(dist[nbour], nbour));

				parent[nbour] = u;
			}else if(dist[nbour] == dist[u] + w){
				if(u == h || u == g || nbour == g || nbour == h)
					parent[nbour] = u;
			}
		}
	}

}

int main(){

	int t;
	cin >> t;

	while(t--){
		int n, m, v;
		cin >> n >> m >> v;

		int b, g, h;
		cin >> b >> g >> h;

		adj_list = vvii(n + 1, vii());
		int x, y, l;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> l;
			adj_list[x].push_back(make_pair(y, l));
			adj_list[y].push_back(make_pair(x, l));
		}

		dest = vi(v);
		for(int i = 0; i < v; i++)
			cin >> dest[i];

		parent = vi(n + 1, -1);
		djikstra_biased(b, g, h, n);

		si ans = si();
		for(int i = 0; i < v; i++){

			int cur = dest[i];
			while(cur != -1){
				
				if( (cur == g && parent[cur] == h) || (cur == h && parent[cur] == g)){
					ans.insert(dest[i]);
					break;
				}

				cur = parent[cur];
			}

		}

		for(si::iterator it = ans.begin(); it != ans.end(); it++){
			cout << *it << " ";
		}
		cout << endl;
	}

	return 0;
}