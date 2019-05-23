#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int>		vi;
typedef vector<vi>		vvi;
typedef long long int 	ll;
typedef vector<ll> 		vll;
typedef vector<vll>		vvll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	vvi a, opt_c;
	vvll opt_v;
	while(cin >> n >> m){
		a = vvi(n, vi(m));
		opt_v = vvll(n, vll(m));
		opt_c = vvi(n, vi(m));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];

		for(int i = 0; i < n; i++)
			opt_v[i][m - 1] = a[i][m - 1];
		for(int j = m - 2; j >= 0; j--){
			for(int i = 0; i < n; i++){
				opt_v[i][j] = min(opt_v[(i - 1 + n) % n][j + 1], min(opt_v[i][j + 1], opt_v[(i + 1) % n][j + 1]));
				vi options;
				if(opt_v[(i - 1 + n) % n][j + 1] == opt_v[i][j]) options.push_back((i - 1 + n) % n);
				if(opt_v[i][j + 1] == opt_v[i][j]) options.push_back(i);
				if(opt_v[(i + 1) % n][j + 1] == opt_v[i][j]) options.push_back((i + 1) % n);
				sort(options.begin(), options.end());
				opt_c[i][j] = options[0];
				opt_v[i][j] += a[i][j];
			}
		}

		ll ans_v = LONG_MAX;
		for(int i = 0; i < n; i++){
			ans_v = min(ans_v, opt_v[i][0]);
		}

		int ans_c = -1;
		for(int i = 0; i < n; i++){
			if(opt_v[i][0] == ans_v){
				ans_c = i;
				break;
			}
		}

		int i = ans_c;
		for(int j = 0; j < m; j++){
			cout << i + 1;
			if(j < m - 1)
				cout << " ";
			i = opt_c[i][j];
		}
		cout << endl;
		cout << ans_v << endl;
	}

	return 0;
}