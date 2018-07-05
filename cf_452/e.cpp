/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef set<iii> siii;

vi a;
vi parent, left_root, right_root;
map<int, iii> m; //maps to (num_elem, start_index, value)

iii make_triplet(int a, int b, int c){
	return make_pair(a, make_pair(b, c));
}

iii dummy = make_triplet(-1, 1, -1);

void make_dsu(int n){
	for(int i = 0; i < n; i++){
		parent[i] = i;
		m[i] = make_triplet(1, -i, a[i]);
	}
}

int get_root(int s){
	if(parent[s] != s)
		parent[s] = get_root(parent[s]);
	return parent[s];
}

void make_union(int x, int y){
	int x_root = get_root(x);
	int y_root = get_root(y);

	parent[y_root] = x_root;
	// int start_index = minimum(-m[x_root].second.first, -m[y_root].second.first);
	// m[x_root] = make_triplet(m[x_root].first + m[y_root].first, -start_index, a[start_index]);
	m[y_root] = dummy;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	parent = vi(n);
	a = vi(n);
	m = map<int, iii>();
	make_dsu(n);

	last_root = 0;
	for(int i = 0; i < n; i++){
		if(i > 0 && a[i] == a[i - 1]){
			make_union(i - 1, i);
		}else
			last_root = i;
	}

	left_root[0] = -1;
	last_root = get_root(0);
	for(int i = 1; i < n; i++){
		if(m[i] != dummy){
			left_root[i] = 
		}
	}

	siii q;
	for(int i = 0; i < n; i++){
		if(m[i] != dummy)
			q.insert(m[i]);
	}

	int ans = 0;
	while(!q.empty()){
		iii mx = *q.rbegin();
		q.erase(mx);
		ans++;

		mx.second.first = -mx.second.first;
		if(mx.second.first == 0 || m[get_root(mx.second.first - 1)] == dummy)
	}

	return 0;
}