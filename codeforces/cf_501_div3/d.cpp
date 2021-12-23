#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k, s;
	cin >> n >> k >> s;

	if(s >= k && (s <= k * (n - 1)) ){
		cout << "YES" << endl;
		ll c = s / (n - 1);

		int loc = 1;
		for(int i = 0; i < c; i++){
			loc = (loc == 1  ? n : 1);
			cout << loc << " ";
		}

		k -= c;

		if(loc == 1){
			ll jumps = 0;
			while(k > 1){
				loc++;
				cout << loc << " ";

				k--;
				jumps++;
			}
			cout << loc + s - c * (n - 1) - jumps;
		}else if(loc == n){

			ll jumps = 0;
			while(k > 1){
				loc--;
				cout << loc << " ";

				k--;
				jumps++;
			}

			cout << loc - (s - c * (n - 1) - jumps);
		}
	}else
		cout << "NO";

	return 0;
}