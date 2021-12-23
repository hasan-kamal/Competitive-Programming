#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi>	vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	while(cin >> n){

		vvi a(n, vi(n));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> a[i][j];
		}

		// preprocess vertical sums
		vvi v_up(n, vi(n, 0));
		for(int j = 0; j < n; j++)
			v_up[0][j] = a[0][j];
		for(int i = 1; i < n; i++)
			for(int j = 0; j < n; j++)
				v_up[i][j] = v_up[i - 1][j] + a[i][j];

		// preprocess running sums
		vvi rsum(n, vi(n, 0));
		for(int i = 0; i < n; i++){
			rsum[i][0] = v_up[i][0];
			for(int j = 1; j < n; j++)
				rsum[i][j] = rsum[i][j - 1] + v_up[i][j];
		}

		int ans = INT_MIN;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(int k = i; k < n; k++){
					for(int l = j; l < n; l++){
						int a = j - 1 >= 0 ? rsum[k][j - 1] : 0;
						int b = i - 1 >= 0 ? rsum[i - 1][l] : 0;
						int c = (i - 1 >= 0 && j - 1 >= 0) ? rsum[i - 1][j - 1] : 0;
						ans = max(ans, rsum[k][l] - a - b + c);
					}
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}