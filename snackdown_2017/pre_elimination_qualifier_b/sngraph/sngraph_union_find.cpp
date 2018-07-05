/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef set<iii> siii;

struct union_find{
	vi p;
	vi rank;
	int n;
	int num_components;
};

void init(union_find &u, int n){
	u.p = vi(n);
	u.rank = vi(n);
	u.n = n;
	for(int i = 0; i < n; i++){
		u.p[i] = i;
		u.rank[i] = 0;
	}
	u.num_components = n;
}

int root(union_find &u, int r){
	if(u.p[r] != r){
		u.p[r] = root(u, u.p[r]);
	}
	return u.p[r];
}

void union_f(union_find &u, int u1, int u2){
	int r1  = root(u, u1);
	int r2 = root(u, u2);
	if(r1 == r2)
		return;

	if(u.rank[r1] > u.rank[r2]){
		//merge u2 into u1
		u.p[r2] = r1;
	}else if(u.rank[u2] > u.rank[u1]){
		//merge u1 into u2
		u.p[r1] = r2;
	}else{
		u.p[r1] = r2;
		u.rank[r2]++;
	}

	u.num_components--;
}

int num_components(union_find &u){
	return u.num_components;
}

int minimum(int x, int y){
	return x < y ? x : y;
}

int maximum(int x, int y){
	return x > y ? x : y;
}

int main(){

	int t;
	cin >> t;

	int n, m;
	vvi adj_list;
	while(t--){

		cin >> n >> m;
		adj_list = vvi(n, vi());
		

		siii edges = siii();
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		vi degree = vi(n);
		for(int i = 0; i < n; i++){
			degree[i] = (int) adj_list[i].size();
		}

		for(int i = 0; i < n; i++){
			for(int nbour : adj_list[i]){
				int mn = minimum(i, nbour);
				int mx = maximum(i, nbour);
				edges.insert(make_pair(minimum(degree[i], degree[nbour]), make_pair(mn, mx)));
			}
		}

		union_find u;
		init(u, n);

		vi ans = vi(n);
		for(int d = n - 1; d >= 0; d--){

			while( !edges.empty() && (*edges.rbegin()).first > d ){
				iii e = (*edges.rbegin());
				union_f(u, e.second.first, e.second.second);
				edges.erase(e);
			}

			ans[d] = num_components(u) - 1;
		}

		for(int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}