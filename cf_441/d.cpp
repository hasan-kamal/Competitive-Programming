/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;

void tree_update(vi &tree, int v, int start, int end, int index){
	if(start == end){
		tree[v] = 1;
		return;
	}

	int mid = start + (end - start) / 2;
	if(index <= mid){
		tree_update(tree, 2 * v, start, mid, index);
	}else{
		tree_update(tree, 2 * v + 1, mid + 1, end, index);
	}

	tree[v] = tree[2 * v] + tree[2 * v + 1];
}

int tree_query(vi &tree, int v, int start, int end, int index_max){

	if(start == end){
		if(start == index_max)
			return tree[v];
		else
			return 0;
	}

	int mid = start + (end - start) / 2;
	if(mid <= index_max){
		return tree[2 * v] + tree_query(tree, 2 * v + 1, mid + 1, end, index_max);
	}else{
		return tree_query(tree, 2 * v, start, mid, index_max);
	}

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi p = vi(n);
	si x_pos = si();
	for(int i = 0; i < n; i++){
		cin >> p[i];
		x_pos.insert(i + 1);
	}

	vi segtree = vi(4 * n + 4, 0);

	cout << "1 ";
	for(int i = 0; i < n; i++){
		x_pos.erase(p[i]);
		tree_update(segtree, 1, 1, n, p[i]);
		
		if(x_pos.empty()){
			cout << 1 << " ";
			continue;
		}
		int last_x_pos = *(x_pos.rbegin());
		int num_o_before_last_x_pos = tree_query(segtree, 1, 1, n, last_x_pos);
		
		cout << 1 + num_o_before_last_x_pos << " ";
	}

	return 0;
}