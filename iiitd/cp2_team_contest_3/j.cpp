/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef vector<char> vc;
typedef vector<vc> vvc;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll m, n;
	cin >> m >> n;

	vvc grid(m + 1, vc(n + 1));
	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= n; j++){
			cin >> grid[i][j];
		}
	}

	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= n; j++){
			if(grid[i][j] == 'B'){
				
				for(ll x = 1; x <= i; x++)
					for(ll y = 1; y <= j; y++){
						if(grid[x][y] == 'R'){
							cout << 0;
							return 0;
						}
						grid[x][y] = 'B';
					}

			}else if(grid[i][j] == 'R'){

				for(ll x = i; x <= m; x++)
					for(ll y = j; y <= n; y++){
						if(grid[x][y] == 'B'){
							cout << 0;
							return 0;
						}
						grid[x][y] = 'R';
					}

			}
		}
	}

	vll a(m + 1);
	vll b(m + 1);

	for(ll i = 1; i <= m; i++){
		a[i] = b[i] = -1;

		bool dots = false;
		for(ll j = 1; j <= n; j++){
			if(grid[i][j] == '.' && !dots){
				a[i] = j;
				dots = true;
			}

			if(dots && grid[i][j] != '.'){
				b[i] = j - 1;
				dots = false;
			}
		}

		if(dots && b[i] == -1){
			b[i] = n;
		}

		if(a[i] == -1){
			// no dots
			// b[i] = last blue
			if(grid[i][1] == 'R')
				b[i] = 0;
			else if(grid[i][n] == 'B')
				b[i] = n;
			else{
				for(ll ind = 1; ind <= n - 1; ind++){
					if(grid[i][ind + 1] == 'R'){
						b[i] = ind;
						break;
					}
				}
			}

			a[i] = b[i] + 1; // first red
		}
	}

	vvll f(m + 1, vll(n + 1, 0));

	// base
	for(ll beta = 0; beta <= n; beta++){
		f[m][beta] = 0;
	}
	for(ll k = a[m] - 1; k <= b[m]; k++){
		f[m][k] = 1;
	}

	// continuation
	for(ll i = m - 1; i >= 1; i--){
		for(ll beta = 0; beta <= n; beta++)
			f[i][beta] = 0;
		for(ll k = a[i] - 1; k <= b[i]; k++){
			f[i][k] = 0;
			for(ll alpha = k; alpha >= a[i + 1] - 1; alpha--)
				f[i][k] += f[i + 1][alpha];
		}
	}

	ll ans = 0;
	for(ll alpha = a[1] - 1; alpha <= b[1]; alpha++){
		ans += f[1][alpha];
	}

	cout << ans;


	return 0;
}