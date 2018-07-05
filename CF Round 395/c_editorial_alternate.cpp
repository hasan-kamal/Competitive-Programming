/*

@author Hasan Kamal

*/

#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

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

	int num_bicolor_edges = 0;
	for(int i=0; i<n; i++)
		for(int nbour : adj_list[i])
			if(color[i]!=color[nbour])
				num_bicolor_edges++;
	num_bicolor_edges/=2;

	for(int i=0; i<n; i++){
		int num_edges_different_color = 0;
		
		for(int nbour : adj_list[i])
			if(color[nbour]!=color[i])
				num_edges_different_color++;

		if(num_bicolor_edges-num_edges_different_color<=0){
			cout<<"YES"<<endl<<i+1;
			return 0;
		}
	}

	cout<<"NO";

	return 0;
}