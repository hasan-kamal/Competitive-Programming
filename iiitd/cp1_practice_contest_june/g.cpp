/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class edge{
public:
	int u, v, w;
	inline bool operator<(const edge& e2) const{
		return w < e2.w;
	}
};

typedef vector<edge> ve;
typedef vector<int> vi;

class disjoint_union{
private:
	vi p;
	int root(int u){
		if(p[u] == u)
			return u;
		p[u] = root(p[u]);
		return p[u];
	}
public:
	disjoint_union(int n){
		p = vi(n + 1);
		for(int i = 1; i <= n; i++)
			p[i] = i;
	}
	bool check_union(int u, int v){
		return root(u) != root(v);
	}
	void union_find(int u, int v){
		int x = root(u);
		int y = root(v);
		if(x == y)
			return;
		p[x] = y;
	}
};


int main(){

	int n, m;
	cin >> n >> m;

	ve edges = ve(m);
	for(int i = 0; i < m; i++){
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	}

	disjoint_union dsu(n);

	sort(edges.begin(), edges.end());
	vi is_not_possible = vi(m, 0);
	int last_weight_done = -1;

	for(int i = 0; i < m; i++){

		if(edges[i].w > last_weight_done){

			int j = i;

			while(j < m && edges[j].w == edges[i].w){
				if(!dsu.check_union(edges[j].u, edges[j].v))
					is_not_possible[j] = 1;
				j++;
			}

			last_weight_done = edges[i].w;
		}

		if(dsu.check_union(edges[i].u, edges[i].v))
			dsu.union_find(edges[i].u, edges[i].v);

	}

	int sum = 0;
	for(int i = 0; i < m; i++)
		sum += is_not_possible[i];
	cout << sum << endl;

	return 0;
}