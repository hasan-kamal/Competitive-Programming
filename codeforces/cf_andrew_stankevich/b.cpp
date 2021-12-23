/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> matrix;
typedef vector<matrix> vm;
int r;

matrix combine(matrix &m1, matrix &m2){
	matrix m;
	m.first.first = ( ((m1.first.first * m2.first.first) % r) + ((m1.first.second * m2.second.first) % r) ) % r;
	m.first.second = ( ((m1.first.first * m2.first.second) % r) + ((m1.first.second * m2.second.second) % r) ) % r;
	m.second.first = ( ((m1.second.first * m2.first.first) % r) + ((m1.second.second * m2.second.first) % r) ) % r;
	m.second.second = ( ((m1.second.first * m2.first.second) % r) + (( m1.second.second * m2.second.second ) % r) ) % r;
	return m;
}

vm tree;
void build_tree(vm &a, int v, int start, int end){
	if(start == end){
		tree[v] = a[start];
		return;
	}

	int mid = start + (end - start) / 2;
	build_tree(a, 2 * v, start, mid);
	build_tree(a, 2 * v + 1, mid + 1, end);
	tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
}

matrix query(int v, int start, int end, int l, int r){
	if(start == l && end == r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	if(r <= mid){
		return query(2 * v, start, mid, l, r);
	}else if(mid < l){
		return query(2 * v + 1, mid + 1, end, l, r);
	}else{
		matrix l_child = query(2 * v, start, mid, l, mid);
		matrix r_child = query(2 * v + 1, mid + 1, end, mid + 1, r);
		return combine(l_child, r_child);
	}	
}

void display(matrix m){
	cout << m.first.first << " " << m.first.second << endl;
	cout << m.second.first << " " << m.second.second << endl;
}

int main(){

	freopen("crypto.in", "r", stdin);
	freopen("crypto.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> r >> n >> m;

	vm a = vm(2 * n);
	for(int i = 1; i <= n; i++){
		matrix m;
		cin >> m.first.first >> m.first.second;
		cin >> m.second.first >> m.second.second;
		a[i] = m;
	}

	tree = vm(5 * n);
	build_tree(a, 1, 1, n);
	
	for(int i = 0; i < m; i++){
		int s, e;
		cin >> s >> e;
		display(query(1, 1, n, s, e));
		cout << endl;
	}

	return 0;
}