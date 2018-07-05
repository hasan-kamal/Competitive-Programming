/*

@author Hasan Kamal

*/

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

class seg_tree{
	vi tree;
	
public:
	seg_tree(int n){
		tree = vi(4 * n);
	}

	void build_tree(int v, int start, int end, vi &a){
		if(start == end){
			tree[v] = a[start];
			return;
		}

		int mid = start + (end - start) / 2;
		build_tree(2 * v, start, mid, a);
		build_tree(2 * v + 1, mid + 1, end, a);

		tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
	}

	int query(int v, int start, int end, int l, int r){
		if(start == l && end == r){
			return tree[v];
		}
		
		int mid = start + (end - start) / 2;
		if(r <= mid)
			return query(2 * v, start, mid, l, r);
		else if(mid < l)
			return query(2 * v + 1, mid + 1, end, l, r);

		int l_child = query(2 * v, start, mid, l, mid);
		int r_child = query(2 * v + 1, mid + 1, end, mid + 1, r);
		return combine(l_child, r_child);
	}

	void update(int v, int start, int end, int index, int new_val){
		if(start == end){
			tree[v] = new_val;
			return;
		}

		int mid = start + (end - start) / 2;
		if(index <= mid){
			update(2 * v, start, mid, index, new_val);
		}else{
			update(2 * v + 1, mid + 1, end, index, new_val);
		}

		tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
	}

	virtual int combine(int l, int r){
		return -1;
	}
};

class max_seg_tree : public seg_tree{
public:
	max_seg_tree(int n) : seg_tree(n){
	}
	int combine(int l, int r){
		return l > r ? l : r;
	}
};

class min_segtree : public seg_tree{
public:
	min_segtree(int n) : seg_tree(n){

	}
	int combine(int l, int r){
		return l < r ? l : r;
	}
};

int main(){

	int n, q;
	scanf("%d %d", &n, &q);

	vi a = vi(n + 1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	max_seg_tree max_tree = max_seg_tree(n);
	max_tree.build_tree(1, 1, n, a);

	min_segtree min_tree = min_segtree(n);
	min_tree.build_tree(1, 1, n, a);

	int ch, b, c;
	while(q--){
		scanf("%d %d %d", &ch, &b, &c);
		if(ch == 1){
			int mx = max_tree.query(1, 1, n, b, c);
			int mn = min_tree.query(1, 1, n, b, c);
			printf("%d\n", mx - mn);
		}else{
			max_tree.update(1, 1, n, b, c);
			min_tree.update(1, 1, n, b, c);
		}
		
	}

	return 0;
}