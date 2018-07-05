/*

@author Hasan Kamal
Problem Election Posters - SPOJ

*/

#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#define M 10000000
using namespace std;

typedef vector<int> vi;
typedef set<int> si;

vi tree;
void paint_tree(int v, int start, int end, int l, int r, int color_id){

	
	if(start != end && tree[v] != 0){
		tree[2 * v] = tree[v];
		tree[2 * v + 1] = tree[v];
	}
	tree[v] = 0;
	
	if(start == l && end == r){
		tree[v] = color_id;

		if(start != end){
			tree[2 * v] = color_id;
			tree[2 * v + 1] = color_id;
		}
		return;

	}

	int mid = start + (end - start) / 2;
	if(mid < l){
		paint_tree(2 * v + 1, mid + 1, end, l, r, color_id);
	}else if(r <= mid){
		paint_tree(2 * v, start, mid, l, r, color_id);
	}else{
		paint_tree(2 * v, start, mid, l, mid, color_id);
		paint_tree(2 * v + 1, mid + 1, end, mid + 1, r, color_id);
	}

}

si colors_collected;
void traverse_tree(int v, int start, int end){

	if(start == end){
		if(tree[v] != 0)
			colors_collected.insert(tree[v]);
		return;
	}

	if(tree[v] != 0){
		colors_collected.insert(tree[v]);
		return;
	}

	int mid = start + (end - start) / 2;
	traverse_tree(2 * v, start, mid);
	traverse_tree(2 * v + 1, mid + 1, end);

}

void disp_tree(int v, int start, int end, int indentation){
	string str = "";
	for(int i = 0; i < indentation; i++)
		str += "\t";

	cout << str << "node v=" << v << " [" << start << ", " << end << "] tree[v]=" << tree[v] << endl;
	if(start == end)
		return;

	int mid = start + (end - start) / 2;
	disp_tree(2 * v, start, mid, indentation + 1);
	disp_tree(2 * v + 1, mid + 1, end, indentation + 1);
}

int main(){

	int t;
	scanf("%d", &t);

	tree = vi(4 * M);

	while(t--){

		for(int i = 0; i < 4 * M; i++)
			tree[i] = 0;
		
		int n;
		scanf("%d", &n);

		int l, r;
		for(int i = 1; i <= n; i++){
			scanf("%d %d", &l, &r);
			paint_tree(1, 1, M, l, r, i);
		}

		colors_collected = si();
		traverse_tree(1, 1, M);
		
		printf("%d\n", (int)colors_collected.size());

	}

	return 0;
}