/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vi dist;

void djikstra(vvii &adj_list, int source, int n){
	//use set as our prioirty queue because
	//STL's priority queue does not support
	//decrease_key operation
	set<ii> q;

	for(int i=0; i<n; i++){
		if(i==source)
			continue;
		dist[i] = INT_MAX;
		q.insert(ii(INT_MAX, i));
	}
	
	dist[source] = 0;
	q.insert(ii(0, source));

	while(!q.empty()){

		//extract_min operation
		ii mn = *q.begin();
		q.erase(mn); //extract_min removes the element also

		// to avoid integer overflow below (since we're using INT_MAX),
		// can add if(mn.first == INT_MAX) break;
		// because if we get a node that is not reachable,
		// then all further ones would definitely not be reachable
		// important, otherwise program will crash if
		// every node is not reachable from s!

		for(ii &nbour : adj_list[mn.second]){
			if(dist[nbour.first]>dist[mn.second]+nbour.second){
				//decrease_key operation
				//we do it by simply removing old entry and adding new entry!
				q.erase(ii(dist[nbour.first], nbour.first));
				dist[nbour.first] = dist[mn.second]+nbour.second;
				q.insert(ii(dist[nbour.first], nbour.first));
			}
		}
	}
}

int main(){

	int n, m;
	cin>>n>>m;

	vvii adj_list(n);
	int a, b, w;
	for(int i=0; i<m; i++){
		cin>>a>>b>>w;
		a--;
		b--;
		adj_list[a].push_back(ii(b, w));
	}

	dist = vi(n);
	djikstra(adj_list, 0, n);
	for(int i=0; i<n; i++)
		cout<<i+1<<":"<<dist[i]<<endl;

	return 0;
}