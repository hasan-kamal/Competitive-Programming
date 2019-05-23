// cf #551 problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int 	ll;

vi min_max;
vvi children;
vi v, l, r;

void dfs(int s){
	if(children[s].empty()){
		// leaf
		v[s] = l[s] = r[s] = 1;
		return;
	}

	// subproblems
	v[s] = 0;
	int n_children = children[s].size();
	for(int i = 0; i < n_children; i++){
		int child = children[s][i];
		dfs(child);
		v[s] += v[child];
	}

	if(min_max[s]){
		// max node
		l[s] = 0;
		r[s] = -1;
		for(int i = 0; i < n_children; i++){
			int child = children[s][i];
			l[s] += l[child];
			r[s] = max(r[s], v[s] - (v[child] - r[child]));
		}
	}else{
		// min node
		l[s] = INT_MAX;
		r[s] = v[s] + 1;
		for(int i = 0; i < n_children; i++){
			int child = children[s][i];
			l[s] = min(l[s], l[child]);
			r[s] -= (v[child] - r[child] + 1);
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	min_max = vi(n, -1);
	for(int i = 0; i < n; i++)
		cin >> min_max[i];

	children = vvi(n, vi());
	int temp;
	for(int i = 1; i < n; i++){
		cin >> temp;
		temp--;
		children[temp].push_back(i);
	}

	v = vi(n);
	l = vi(n);
	r = vi(n);
	dfs(0);

	cout << r[0];

	return 0;
}