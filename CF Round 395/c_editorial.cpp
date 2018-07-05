/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

bool is_valid_root(int s, vvi &list, vi &color){
	int num_edges_distinct_color = 0;
	int n = int(list.size());
	for(int i=0; i<n; i++){
		for(int nbour : list[i])
			if(color[i]!=color[nbour])
				num_edges_distinct_color++;
	}
	num_edges_distinct_color/=2;

	int num_edges_distinct_incident_s = 0;
	for(int nbour : list[s])
		if(color[nbour]!=color[s])
			num_edges_distinct_incident_s++;

	if(num_edges_distinct_color>num_edges_distinct_incident_s)
		return false;
	else
		return true;
}

int main(){

	int n;
	cin>>n;

	vvi adj_list(n);
	int u, v;
	for(int i=0; i<n-1; i++){
		cin>>u>>v;
		u--;
		v--;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vi color(n);
	for(int i=0; i<n; i++)
		cin>>color[i];

	for(int i=0; i<n; i++){
		for(int nbour : adj_list[i]){
			if(color[nbour]!=color[i]){

				bool r1 = is_valid_root(i, adj_list, color);

				bool r2 = is_valid_root(nbour, adj_list, color);

				if(r1==false && r2==false)
					cout<<"NO";
				else
					cout<<"YES"<<endl<<((r1)?i+1:nbour+1);

				return 0;
			}
		}
	}

	cout<<"YES"<<endl<<1;

	return 0;
}