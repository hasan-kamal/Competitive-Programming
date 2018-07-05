/*

@author Hasan Kamal
Problem KQUERY - SPOJ

*/

#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi a;
vvi tree;
void build(int v, int start, int end){

	if(start == end){
		tree[v].push_back(a[start]);
		return;
	}

	int mid = start + (end - start) / 2;
	build(2 * v, start, mid);
	build(2 * v + 1, mid + 1, end);

	tree[2 * v].push_back(INT_MAX);
	tree[2 * v + 1].push_back(INT_MAX);

	int x1 = 0;
	int x2 = 0;

	while(tree[2 * v][x1]!= INT_MAX || tree[2 * v + 1][x2]!=INT_MAX){
		if(tree[2 * v][x1] < tree[2 * v + 1][x2]){
			tree[v].push_back(tree[2 * v][x1]);
			x1++;
		}else{
			tree[v].push_back(tree[2 * v + 1][x2]);
			x2++;
		}
	}

	tree[2 * v].pop_back();
	tree[2 * v + 1].pop_back();

}

int query(int v, int start, int end, int l, int r, int k){

	if(start == l && end == r){
		return tree[v].size() - ( upper_bound(tree[v].begin(), tree[v].end(), k) - tree[v].begin() );
	}

	int mid = start + (end - start) / 2;
	if(mid < l){
		return query(2 * v + 1, mid + 1, end, l, r, k);
	}else if(r <= mid){
		return query(2 * v, start, mid, l, r, k);
	}

	int l_side = query(2 * v, start, mid, l, mid, k);
	int r_side = query(2 * v + 1, mid + 1, end, mid + 1, r, k);
	return l_side + r_side;

}

int main(){

	int n;
	scanf("%d", &n);

	a = vi(n + 1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	tree = vvi(4 * n, vi());
	build(1, 1, n);

	int q;
	scanf("%d", &q);

	int i, j, k;
	while(q--){
		scanf("%d %d %d", &i, &j, &k);
		printf("%d\n", query(1, 1, n, i, j, k));
	}

	return 0;
}