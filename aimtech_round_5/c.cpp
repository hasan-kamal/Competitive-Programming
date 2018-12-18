#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef struct{
	int x1, y1, x2, y2;
} rect;
typedef vector<rect> vr;

vr a;
vr tree;

rect combine(rect r1, rect r2){
	rect ans;
	ans.x1 = max(r1.x1, r2.x1);
	ans.y1 = max(r1.y1, r2.y1);
	ans.x2 = min(r1.x2, r2.x2);
	ans.y2 = min(r1.y2, r2.y2);
	return ans;
}

void build_tree(int v, int l, int r){
	if(l == r){
		tree[v] = a[l];
		return;
	}

	int mid = l + (r - l) / 2;
	build_tree(2 * v, l, mid);
	build_tree(2 * v + 1, mid + 1, r);

	tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
}

rect query_tree(int v, int l, int r, int start, int end){
	if(l == start && r == end){
		return tree[v];
	}

	int mid = l + (r - l) / 2;
	if(end <= mid){
		return query_tree(2 * v, l, mid, start, end);
	}else if(mid < start){
		return query_tree(2 * v + 1, mid + 1, r, start, end);
	}else{
		rect l_child = query_tree(2 * v, l, mid, start, mid);
		rect r_child = query_tree(2 * v + 1, mid + 1, r, mid + 1, end);
		return combine(l_child, r_child);
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	a = vr(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;

	tree = vr(5 * n + 5);
	build_tree(1, 1, n);

	// check for [2, n]
	rect r = query_tree(1, 1, n, 2, n);
	if(r.x1 <= r.x2 && r.y1 <= r.y2){
		cout << r.x1 << " " << r.y1;
		return 0;
	}

	// check for [1, n - 1]
	r = query_tree(1, 1, n, 1, n - 1);
	if(r.x1 <= r.x2 && r.y1 <= r.y2){
		cout << r.x1 << " " << r.y1;
		return 0;
	}

	for(int i = 2; i < n; i++){
		// try by excluding i-th
		rect r1 = query_tree(1, 1, n, 1, i - 1);
		rect r2 = query_tree(1, 1, n, i + 1, n);
		r = combine(r1, r2);
		if(r.x1 <= r.x2 && r.y1 <= r.y2){
			cout << r.x1 << " " << r.y1;
			return 0;
		}
	}

	return 0;
}