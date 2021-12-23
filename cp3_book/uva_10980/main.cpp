#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <sstream>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;

typedef vector<double>		vd;

void disp(vi &a){
	for(int i = 0; i < (int)a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

void disp(vd &a){
	for(int i = 0; i < (int)a.size(); i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double unit;
	int m, t = 0;
	vi n, k;
	vd p, dp;
	string line;
	while(cin >> unit >> m){
		p = vd(m + 1);
		n = vi(m + 1);
		for(int i = 1; i <= m; i++)
			cin >> n[i] >> p[i];
		n[0] = 1;
		p[0] = unit;

		getline(cin, line);
		getline(cin, line);
		istringstream is(line);

		k = vi();
		int v;
		while(is >> v){
			k.push_back(v);
		}

		// cout << line << endl;
		// cout << "n: "; disp(n);
		// cout << "p: "; disp(p);
		// cout << "k: "; disp(k);

		int k_max = *max_element(k.begin(), k.end());

		// create dp
		dp = vd(k_max + 1, INT_MAX);
		dp[0] = 0;
		for(int b = 1; b <= k_max; b++){
			for(int i = 0; i <= m; i++){
				if(b - n[i] > 0 && dp[b - n[i]] != INT_MAX)
					dp[b] = min(dp[b], p[i] + dp[b - n[i]]);
				else if(b - n[i] <= 0)
					dp[b] = min(dp[b], p[i]);
			}
		}

		printf("Case %d:\n", ++t);
		for(int i = 0; i < (int)k.size(); i++)
			printf("Buy %d for $%.2lf\n", k[i], dp[k[i]]);
	}

	return 0;
}