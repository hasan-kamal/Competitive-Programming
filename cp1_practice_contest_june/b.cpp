/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
#define INFINITY 50000001
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<int> si;
typedef set<ii> sii;

int minimum(int x, int y){
	return x < y ? x : y;
}

void djikstra(int s, int n, vi &dist, vvii &adj_list){
	
	sii q = sii();
	
	for(int i = 1; i <= n; i++){
		dist[i] = INFINITY;
		q.insert(make_pair(INFINITY, i));
	}

	dist[s] = 0;
	q.erase(make_pair(INFINITY, s));
	q.insert(make_pair(0, s));

	while(!q.empty()){
		ii smallest = *q.begin();
		int u = smallest.second;
		q.erase(smallest);

		for(ii &nbour : adj_list[u]){
			if(dist[nbour.first] > dist[u] + nbour.second){
				q.erase(make_pair(dist[nbour.first], nbour.first));
				dist[nbour.first] = dist[u] + nbour.second;
				q.insert(make_pair(dist[nbour.first], nbour.first));
			}
		}
	}

}

void disp_vector(vi &a, int start, int end){
	for(int i = start; i <= end; i++)
		cout << i <<")" << a[i] << " ";
	cout << endl;
}

int main(){

	int t;
	cin >> t;

	vvii adj_list;
	vi destinations;

	while(t--){

		int n, m, v;
		cin >> n >> m >> v;

		int b, g, h;
		cin >> b >> g >> h;

		adj_list = vvii(n + 1, vii());
		int x, y, l, w_gh;
		for(int i = 0; i < m; i++){
			cin >> x >> y >> l;
			adj_list[x].push_back(make_pair(y, l));
			adj_list[y].push_back(make_pair(x, l));
			if( (x == g && y == h) || (x == h && y == g) )
				w_gh = l;
		}

		destinations = vi(v);
		for(int i = 0; i < v; i++)
			cin >> destinations[i];

		vi b_distance = vi(n + 1, INFINITY);
		djikstra(b, n, b_distance, adj_list);

		vi g_distance = vi(n + 1, INFINITY);
		djikstra(g, n, g_distance, adj_list);

		vi h_distance = vi(n + 1, INFINITY);
		djikstra(h, n, h_distance, adj_list);

		// cout << "b_distance" << endl;
		// disp_vector(b_distance, 1, n);

		// cout << "g_distance" << endl;
		// disp_vector(g_distance, 1, n);

		// cout << "h_distance" << endl;
		// disp_vector(h_distance, 1, n);

		si ans = si();
		for(int i = 0; i < v; i++){
			x = minimum(b_distance[h] + w_gh + g_distance[destinations[i]], b_distance[g] + w_gh + h_distance[destinations[i]]);
			// cout << "debug1:" << w_gh << " " << destinations[i] << " " << b_distance[h] + w_gh + g_distance[destinations[i]] << " " << b_distance[g] + w_gh + h_distance[destinations[i]] << endl;
			// cout << "debug2:" << b_distance[destinations[i]] << " " << x << endl;
			if(b_distance[destinations[i]] == x){
				ans.insert(destinations[i]);
			}
		}

		for(si::iterator it = ans.begin(); it != ans.end(); it++)
			cout << *it << " ";
		cout << endl;
	}

	return 0;
}	