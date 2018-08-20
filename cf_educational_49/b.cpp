#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, q;
	cin >> n >> q;

	while(q--){
		ll x, y;
		cin >> x >> y;

		ll beta = ((n * n) % 2 == 0) ? n * n / 2 + 1 : n * n / 2 + 2;

		if(n % 2 == 1){
			if(x % 2 == 1){
				ll alpha = (x - 1) * n / 2;
				if(y % 2 == 1)
					cout << alpha + 1 + y / 2;
				else
					cout << beta + alpha + (y - 1) / 2;
			}else{
				ll p1 = (x - 2) * n / 2;
				if(y % 2 == 1){
					cout << beta + p1 + (n / 2) + (y - 1) / 2;
				}else{
					cout << p1 + (n / 2) + 1 + y / 2;
				}
			}
		}else{
			ll alpha = (x - 1) * n / 2;
			if(x % 2 == 1){
				if(y % 2 == 1)
					cout << alpha + 1 + y / 2;
				else
					cout << beta + alpha + (y - 1) / 2;
			}else{
				if(y % 2 == 1)
					cout << beta + alpha + (y - 1) / 2;
				else
					cout << alpha + y / 2 ;
			}
		}

		cout << endl;
	}

	return 0;
}