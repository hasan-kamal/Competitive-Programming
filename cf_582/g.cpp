#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> 	vi;
typedef pair<int, int>	ii;
typedef vector<ii>		vii;
typedef vector<vii> 	vvii;
typedef long long int 	ll;
typedef vector<ll> 		vll;
typedef pair<int, ii>	iii;
typedef vector<iii>		viii;

int n, m;

vi parent, size;

// nodes with id 0...n are made i.e. n + 1 nodes are made
void make_set(int n){
	parent = vi(n + 1);
	size = vi(n + 1);
	for(int i = 0; i <= n; i++){
		parent[i] = i;
		size[i] = 1;
	}
}

int root(int id){
	if(id == parent[id])
		return id;
	parent[id] = root(parent[id]);
	return parent[id];
}

long long int component_size(int id){
	return size[root(id)];
}

void do_union(int id1, int id2){
	int temp;
	if(size[root(id1)] < size[root(id2)]){
		temp = id1;
		id1 = id2;
		id2 = temp;
	}

	int r1 = root(id1);
	int r2 = root(id2);
	// id1 is the bigger one
	parent[r2] = r1;
	size[r1] += size[r2];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	viii edges;
	int u, v, w;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v >> w;
		u--; v--;
		edges.push_back({w, {u, v}});
	}
	sort(edges.begin(), edges.end());

	// make set
	make_set(n - 1);

	// compute solutions
	const int Q = 200005;
	vll ans(Q, 0);
	ll new_pairs;
	int i = 0;
	for(int edge_val = 1; edge_val < Q; edge_val++){
		new_pairs = 0;
		while(i < edges.size() && edges[i].first <= edge_val){
			// add this edge
			if(root(edges[i].second.first) != root(edges[i].second.second)){
				new_pairs += component_size(edges[i].second.first) * component_size(edges[i].second.second);
				do_union(edges[i].second.first, edges[i].second.second);
			}
			i++;
		}
		ans[edge_val] = ans[edge_val - 1] + new_pairs;
	}

	int q;
	for(int i = 0; i < m; i++){
		cin >> q;
		cout << ans[q] << " ";
	}

	return 0;
}