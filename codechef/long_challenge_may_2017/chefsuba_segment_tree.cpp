/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int maximum(int x, int y){
	return x < y ? y : x;
}

vi tree;
int build_segment_tree(vi &x, int v, int start, int end){
	if(start == end){
		tree[v] = x[start];
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	int l_max = build_segment_tree(x, 2 * v, start, mid);
	int r_max = build_segment_tree(x, 2 * v + 1, mid + 1, end);

	tree[v] = maximum(l_max, r_max);
	return tree[v];
}

int range_max_tree(int v, int start, int end, int l, int r){
	if(r < start || end < l)
		return -1;

	if(l <= start && end <= r)
		return tree[v];

	int mid = start + (end - start) / 2;
	int l_max = range_max_tree(2 * v, start, mid, l, r);
	int r_max = range_max_tree(2 * v + 1, mid + 1, end, l, r);
	return maximum(l_max, r_max);
}

int main(){

	int n, k, p;
	cin >> n >> k >> p;

	vi a = vi(2 * n + 1);
	int total_sum = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		total_sum += a[i];
		a[n + i] = a[i];
	}

	vi sum_ending = vi(2 * n + 1, 0);

	int temp = 0;
	for(int i = 1; i <= k; i++)
		temp += a[i];
	sum_ending[k] = temp;

	for(int i = k + 1; i <= 2 * n; i++){
		sum_ending[i] = sum_ending[i - 1] + a[i] - a[i - k];
	}

	tree = vi(4 * 2 * n);
	build_segment_tree(sum_ending, 1, 1, 2 * n);

	string s;
	cin >> s;

	int num_rotations = 0;
	for(char &ch : s){

		if(ch == '!'){
			num_rotations++;
			num_rotations = num_rotations % n;
		}else if(ch == '?'){

			if(k >= n){
				cout << total_sum << endl;
				continue;
			}

			int s = n + 1 - num_rotations;
			int e = 2 * n - num_rotations;
			cout << range_max_tree(1, 1, 2 * n, s + k - 1, e) << endl;

		}

	}

	return 0;
}