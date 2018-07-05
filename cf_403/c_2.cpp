/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vvi adj_list;
vi colors;
vi parent_colors;

int bfs_color(int n){
	vi visited(n, 0);
	
	queue<int> q;
	q.push(0);
	visited[0]=1;

	colors[0] = 1;
	parent_colors[0] = -1;

	int max_col_counter = -1;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		int col_counter = 1;
		for(int nbour : adj_list[u]){
			if(!visited[nbour]){
				q.push(nbour);
				visited[nbour] = 1;

				while(col_counter==colors[u] || col_counter==parent_colors[u]){
					//can't use col_counter
					col_counter++;
				}

				if(col_counter>max_col_counter)
					max_col_counter = col_counter;
				
				colors[nbour] = col_counter;
				parent_colors[nbour] = colors[u];

				col_counter++;

			}
		}

	}

	return max_col_counter;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin>>n;

	int a, b;
	adj_list = vvi(n);
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		a--;
		b--;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	colors = vi(n, -1);
	parent_colors = vi(n, -1);
	int k = bfs_color(n);
	cout<<k<<endl;
	for(int i=0; i<n; i++)
		cout<<colors[i]<<" ";

	return 0;
} 