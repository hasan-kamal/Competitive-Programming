/*

@author Hasan Kamal

*/

#include <vector>
#include <iostream>
#include <set>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

vi component_num;

void dfs_visit(vvi &list, vi &visited, int s, int &num, vi &colors){
	visited[s] = 1;
	for(int nbour : list[s])
		if(!visited[nbour]){
			
			if(colors[nbour]!=colors[s]){
				num++;
				component_num[nbour] = num;
			}else{
				component_num[nbour] = component_num[s];
			}

			dfs_visit(list, visited, nbour, num, colors);
		}
}

void dfs_comp(vvi &list, int &num, vi &colors){
	num = 0;

	int n = int(list.size());
	vi visited(n, 0);
	component_num[0] = 1; //assign number 1 to 0th node
	num = 1;

	for(int i=0; i<n; i++)
		if(!visited[i])
			dfs_visit(list, visited, 0, num, colors);
}

int main(){

	int n;
	cin>>n;
	vvi adj_list(n);

	int u, v;
	for(int i=0; i<n-1; i++){
		cin>>u>>v;
		u--; v--;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	vi colors(n);
	for(int i=0; i<n; i++)
		cin>>colors[i];

	component_num.resize(n);
	int num_component;
	dfs_comp(adj_list, num_component, colors);
	//cout<<"num_component is "<<num_component<<endl;

	bool is_possible = false;
	int possible_root = -1;
	for(int i=0; i<n; i++){
		set<int> components_touched;
		components_touched.insert(component_num[i]);

		for(int nbour : adj_list[i]){
			components_touched.insert(component_num[nbour]);
		}

		if(int(components_touched.size())==num_component){
			is_possible = true;
			possible_root = i;
			break;
		}

	}

	if(is_possible)
		cout<<"YES"<<endl<<possible_root+1;
	else
		cout<<"NO";

	return 0;
}