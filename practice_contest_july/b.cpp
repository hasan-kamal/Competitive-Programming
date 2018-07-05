/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int minimum(int x, int y){
	return x < y ? x : y;
}

int maximum(int x, int y){
	return x > y ? x : y;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	vi left = vi(n + 1);
	left[1] = 1;
	for(int i = 2; i <= n; i++)
		left[i] = minimum(a[i], left[i - 1] + 1);

	vi right = vi(n + 1);
	right[n] = 1;
	for(int i = n - 1; i >= 1; i--)
		right[i] = minimum(a[i], right[i + 1] + 1);

	vi t = vi(n + 1);
	for(int i = 1; i <= n; i++)
		t[i] = minimum(left[i], right[i]);

	int max_val = t[1];
	for(int i = 2; i <= n; i++){
		if(t[i] > max_val)
			max_val = t[i];
	}

	cout << max_val;

	return 0;
}