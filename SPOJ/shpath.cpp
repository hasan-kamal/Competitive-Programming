/*

@author Hasan Kamal

*/

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

vvii adj_list;
vi dist;

void djikstra(int source, int n){
	set<ii> q;//first=distance, second=index

	for(int i=0; i<n; i++){
		if(i==source)
			continue;
		dist[i] = INT_MAX;
		q.insert(ii(INT_MAX, i));
	}

	dist[source] = 0;
	q.insert(ii(0, source));


	while(!q.empty()){
		
		//extract min out of priority queue
		ii min_dis = *q.begin();
		q.erase(min_dis);

		for(ii &nbour : adj_list[min_dis.second]){
			//relax all the edges
			if(dist[nbour.first]>dist[min_dis.second]+nbour.second){
				//decrease key operation
				q.erase(ii(dist[nbour.first], nbour.first));
				dist[nbour.first] = dist[min_dis.second] + nbour.second;
				q.insert(ii(dist[nbour.first], nbour.first));
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		
		map<string, int> list_map;

		adj_list = vvii(n);
		dist = vi(n);

		for(int i=0; i<n; i++){
			string s;
			cin>>s;
			list_map[s] = i;

			int num_nb;
			cin>>num_nb;
			while(num_nb--){
				int nbour_index, weight;
				cin>>nbour_index>>weight;
				nbour_index--;
				adj_list[i].push_back(ii(nbour_index, weight));
			}
		}

		int r;
		cin>>r;
		while(r--){
			string s1, s2;
			cin>>s1>>s2;
			djikstra(list_map[s1], n);
			cout<<dist[list_map[s2]]<<endl;	
		}
	}

	return 0;
}