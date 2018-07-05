/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<vector<pii>> vvpii;

vvpii adj_list;
vi s;

void dfs_visit(vi &visited, int source){
	visited[source] = 1;

	for(pii &nbour : adj_list[source]){
		if(!visited[nbour.first]){
			dfs_visit(visited, nbour.first);

			int sums_child=0;
			for(pii x : adj_list[nbour.first])
				sums_child+=(x.second);
			nbour.second = s[nbour.first] + sums_child;
		}
	}
}

void dfs_ans(int n){
	vi visited(n, 0);
	dfs_visit(visited, 0);
}

int main(){

	int n;
	cin>>n;

	s = vi(n);
	int summation_si = 0;
	for(int i=0; i<n; i++){
		cin>>s[i];
		summation_si+=s[i];
	}

	adj_list = vvpii(n);
	int a, b;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		a--;
		b--;
		adj_list[a].push_back(pii(b, 0));
		adj_list[b].push_back(pii(a, 0));
	}

	dfs_ans(n);

	vi ans(n, 0);
	for(int i=0; i<n; i++){

		int mx = -1;

		int sum_one=0;
		for(pii n : adj_list[i]){
			sum_one+=n.second;
			if(n.second>mx)
				mx = n.second;
		}

		if(summation_si-s[i]-sum_one>mx)
			mx = summation_si-s[i]-sum_one;

		ans[i] = mx;
	}

	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	
	return 0;
}