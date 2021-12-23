/*

@author Hasan Kamal

*/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int next(set<int> &used_cols, int min_color_available, int n){
	for(int x=min_color_available+1; x<=n; x++){
		if(used_cols.find(x) == used_cols.end()){
			cout<<"::"<<x<<endl;
		 	return x;
		}
	}

	return -100;
}

void dfs_visit(vvi &adj_list, vi &color, int s, int parent, int gparent){
	
}

int main(){

	int n;
	cin>>n;

	vvi adj_list(n);
	int x, y;

	for(int i=0; i<n-1; i++){
		cin>>x>>y;
		x--;
		y--;
		adj_list[x].push_back(y);
		adj_list[y].push_back(x);
	}	

	vi color(n, -1);
	for(int i=0; i<n; i++){
		if(color[i]==-1)
			dfs_visit(adj_list, color, i, 0, -1);
	}

	int max_color = color[0];
	for(int i=0; i<n; i++)
		if(color[i]>max_color)
			max_color = color[i];
	cout<<max_color<<endl;
	for(int i=0; i<n; i++)
		cout<<color[i]<<" ";

	return 0;
}