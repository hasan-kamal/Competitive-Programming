/*

@author Hasan Kamal
Problem C - Sereja and Brackets #223 CF

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

int minimum(int x, int y){
	return x < y ? x : y;
}

viii tree;
iii build_tree(int v, int start, int end, string &s){
	if(start == end){
		tree[v].first = 0;
		tree[v].second.first = 0;
		tree[v].second.second = 0;
		if(s[start - 1] == '(')
			tree[v].second.first++;
		else
			tree[v].second.second++;
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	iii l_child = build_tree(2 * v, start, mid, s);
	iii r_child = build_tree(2 * v + 1, mid + 1, end, s);

	tree[v].first = l_child.first + r_child.first + 2 * minimum(l_child.second.first, r_child.second.second);
	tree[v].second.first = r_child.second.first + l_child.second.first - minimum(l_child.second.first, r_child.second.second);
	tree[v].second.second = l_child.second.second + r_child.second.second - minimum(l_child.second.first, r_child.second.second);
	return tree[v];
}

iii query_tree(int v, int start, int end, int l, int r){
	if(start == l && end == r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;

	if(mid < l)
		return query_tree(2 * v + 1, mid + 1, end, l, r);
	else if(r <= mid)
		return query_tree(2 * v, start, mid, l, r);

	iii l_child = query_tree(2 * v, start, mid, l, mid);
	iii r_child = query_tree(2 * v + 1, mid + 1, end, mid + 1, r);

	iii combine;
	combine.first = l_child.first + r_child.first + 2 * minimum(l_child.second.first, r_child.second.second);
	combine.second.first = r_child.second.first + l_child.second.first - minimum(l_child.second.first, r_child.second.second);
	combine.second.second = l_child.second.second + r_child.second.second - minimum(l_child.second.first, r_child.second.second);
	return combine;
}

int main(){

	string str;
	cin >> str;

	int n = str.length();

	tree = viii(4 * n);
	build_tree(1, 1, n, str);

	int m;
	cin >> m;

	int l, r;
	while(m--){

		cin >> l >> r;
		cout << query_tree(1, 1, n, l, r).first << endl;

	}

	return 0;
}