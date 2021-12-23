/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

class node{
public:
	int xor_all;
	node* zero;
	node* one;
	node(){
		xor_all = 0;
		zero = nullptr;
		one = nullptr;
	}
};

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<node> vnode;

vnode roots;
vvii adj_list;
vi visited;

void insert_persistent_trie(node& target, node& source, int key){
	node* cur_new = &target;
	node* cur_old = &source;

	int bit;
	int i;
	for(i = 30; i >= 0; i--){
		bit = (key >> i) & 1;
		cur_new->xor_all = cur_old->xor_all ^ key;

		if(bit == 0){

			cur_new->one = cur_old->one;

			cur_new->zero = new node();
			cur_new = cur_new->zero;

			if(cur_old->zero != nullptr)
				cur_old = cur_old->zero;
			else{
				cur_new->xor_all = key;
				break;
			}

		}else{

			cur_new->zero = cur_old->zero;

			cur_new->one = new node();
			cur_new = cur_new->one;

			if(cur_old->one != nullptr)
				cur_old = cur_old->one;
			else{
				cur_new->xor_all = key;
				break;
			}

		}
	}

	i--;
	while(i >= 0){

		bit = (key >> i) & 1;

		if(bit == 0){
			cur_new->zero = new node();
			cur_new->zero->xor_all = key;
			cur_new = cur_new->zero;
		}else{
			cur_new->one = new node();
			cur_new->one->xor_all = key;
			cur_new = cur_new->one;
		}

		i--;
	}
}

void dfs_visit(int s, int p, int c){
	visited[s] = 1;

	if(s == p){
		//root
		insert_persistent_trie(roots[s], roots[s], 0);
	}else{
		insert_persistent_trie(roots[s], roots[p], c);
	}

	for(ii& nbour : adj_list[s]){
		if(visited[nbour.first] == 0)
			dfs_visit(nbour.first, s, nbour.second);
	}
}

void dfs_create_nodes(int n){
	visited = vi(n + 1, 0);

	for(int i = 1; i <= n; i++){
		if(visited[i] == 0)
			dfs_visit(i, i, 0);
	}
}

int find_xor(int v, int k){
	int bit;

	node* cur = &roots[v];
	int ans = 0;

	for(int i = 30; i >= 0; i--){

		if(cur == nullptr)
			break;
		bit = (k >> i) & 1;

		if(bit == 0){
			cur = cur->zero;
		}else{

			if(cur->zero != nullptr){
				ans = ans ^ (cur->zero->xor_all);
			}
			cur = cur->one;

		}
	}

	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;

		adj_list = vvii(n + 1, vii());
		int u, v, c;
		for(int i = 0; i < n - 1; i++){
			cin >> u >> v >> c;
			adj_list[u].push_back(make_pair(v, c));
			adj_list[v].push_back(make_pair(u, c));
		}

		roots = vnode(n + 1, node());
		dfs_create_nodes(n);

		int m;
		cin >> m;

		int k;
		while(m--){
			cin >> u >> v >> k;
			int a = find_xor(u, k + 1);
			int b = find_xor(v, k + 1);
			cout << (a ^ b) << endl;
		}
	}

	return 0;
}