/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
#define D 100005
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> l2;
typedef pair<ll, l2> l3;
typedef vector<l3> vl3;
typedef vector<vl3> vvl3;
typedef set<l3> sl3;

int main(){

	ll t;
	cin >> t;

	ll n, d;
	while(t--){
		cin >> n >> d;

		vvl3 val = vvl3(D, vl3());

		ll dt, tt, st;
		for(ll i = 0; i < n; i++){
			cin >> dt >> tt >> st;
			l3 p;
			p.first = st;
			p.second.first = tt;
			p.second.second = i;
			val[dt].push_back(p);
		}

		sl3 s = sl3();
		for(ll i = 1; i <= d; i++){

			for(l3 p : val[i])
				s.insert(p);

			if(!s.empty()){
				l3 max_val = *s.rbegin();
				s.erase(max_val);
				if(max_val.second.first > 1){
					max_val.second.first -= 1;
					s.insert(max_val);
				}
			}

		}

		ll ans = 0;
		for(sl3::iterator it = s.begin(); it != s.end(); it++){
			l3 p = *it;
			ans = ans + (p.first * p.second.first);
		}

		cout << ans << endl;
	}

	return 0;
}