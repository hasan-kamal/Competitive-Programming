#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef vector<vi> vvi;
typedef set<int> si;

si ans;
vi mark;
vvi adj_list;

void dfs(vi &c, int s){
	// bool down_delete = true;
	// for(int nbour : adj_list[s]){
	// 	dfs(c, nbour);
	// 	if(mark[nbour] == 0)
	// 		down_delete = false;
	// }

	// if(down_delete && c[s] == 1){
	// 	mark[s] = 1;
	// 	ans.insert(s);
	// }

	bool okay = true;
	for(int nbour : adj_list[s]){
		dfs(c, nbour);
		if(c[nbour] == 0)
			okay = false;
	}

	if(okay && c[s] == 1){
		ans.insert(s);
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi p(n + 1);
	vi c(n + 1);
	adj_list = vvi(n + 1);

	int source = -1;
	for(int i = 1; i <= n; i++){
		cin >> p[i] >> c[i];
		if(p[i] == -1)
			source = i;
		else
			adj_list[p[i]].push_back(i);
	}

	mark = vi(n + 1, 0);
	dfs(c, source);

	if(ans.size() == 0){
		cout << -1;
		return 0;
	}

	for(si::iterator it = ans.begin(); it != ans.end(); it++){
		cout << *it << " ";
	}

	return 0;
}