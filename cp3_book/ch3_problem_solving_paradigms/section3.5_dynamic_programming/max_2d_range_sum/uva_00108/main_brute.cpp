#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi>	vvi;

int sum_matrix(vvi &a, int i, int j, int k, int l){
	int ans = 0;
	for(int row = i; row <= k; row++){
		for(int col = j; col <= l; col++)
			ans += a[row][col];
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vvi a(n, vi(n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	
	int ans = INT_MIN;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = i; k < n; k++){
				for(int l = j; l < n; l++){
					ans = max(ans, sum_matrix(a, i, j, k, l));
				}
			}
		}
	}
	cout << ans;

	return 0;
}