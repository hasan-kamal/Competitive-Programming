/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi tree;

void build_tree(int v, int start, int end){

	if(start == end){
		tree[v] = 1;
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);

	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

int query_num_ticks(int v, int start, int end, int l, int r){
	if(start == l && end == r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	if(r <= mid){
		return query_num_ticks(2 * v, start, mid, l, r);
	}else if(mid < l){
		return query_num_ticks(2 * v + 1, mid + 1, end, l, r);
	}else{
		int l_child = query_num_ticks(2 * v, start, mid, l, mid);
		int r_child = query_num_ticks(2 * v + 1, mid + 1, end, mid + 1, r);
		return l_child + r_child;
	}
}

int get_pos_tree(int v, int start, int end, int tick_number){

	if(start == end){
		return start;
	}

	int mid = start + (end - start) / 2;
	if(tick_number <= tree[2 * v]){
		return get_pos_tree(2 * v, start, mid, tick_number);
	}else{
		return get_pos_tree(2 * v + 1, mid + 1, end, tick_number - tree[2 * v]);
	}

}

void update_tree_cross(int v, int start, int end, int index_to_update){

	if(start == end){
		tree[v] = 0;
		return;
	}

	int mid = start + (end - start) / 2;
	if(index_to_update <= mid){
		update_tree_cross(2 * v, start, mid, index_to_update);
	}else{
		update_tree_cross(2 * v + 1, mid + 1, end, index_to_update);
	}

	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

int wrap(int index){
	int num_ticks_total = tree[1];
	int rem = index % num_ticks_total;
	if(rem != 0)
		return rem;
	else
		return num_ticks_total;
}

int main(){

	int t;
	cin >> t;

	int n;
	vi pos;
	while(t--){
		cin >> n;
		
		pos = vi(n + 1, -1);
		tree = vi(4 * n);
		build_tree(1, 1, n);
		int h = 1;
		int t = n;

		int num_ticks_total;
		for(int x = 1; x <= n; x++){
			int k = query_num_ticks(1, 1, n, 1, h);
			int alpha = get_pos_tree(1, 1, n, wrap(k + x)); // in a wrap-around fashion
			int k_ = query_num_ticks(1, 1, n, 1, t);
			int beta = get_pos_tree(1, 1, n, wrap(k_ + x)); // in a wrap-around fashion
			pos[alpha] = x;

			//cout << "card x=" << x << " placed at position=" << alpha << endl;

			if(x == n)
				break;
			update_tree_cross(1, 1, n, alpha);
			int k_d = query_num_ticks(1, 1, n, 1, alpha);
			int gamma = get_pos_tree(1, 1, n, wrap(k_d + 1)); //in a wrap-around fashion again
			h = gamma;
			t = beta;
		}

		for(int i = 1; i <= n; i++)
			cout << pos[i] << " ";
		cout << endl;
	}

	return 0;
}