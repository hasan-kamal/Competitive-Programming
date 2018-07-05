/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll; //will need this
typedef vector<string> vs;
typedef vector<int> vi;

vi a;
vs s;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	const ll max_x = 1e6 + 2;
	a = vi(max_x, 0);

	ll last_pos = -1;

	ll n;
	cin >> n;
	string str;
	ll k, x;
	s = vs(n + 1, "");
	for(ll i = 1; i <= n; i++){
		cin >> str;
		s[i] = str;
		cin >> k;
		while(k--){
			cin >> x;
			if( ( (ll) str.length() ) > ((ll) s[a[x]].length()) ){
				a[x] = i;
			}

			// if( (x + ( (ll) str.length()) - 1) > last_pos){
			// 	last_pos = x + ( (ll) str.length() ) - 1;
			// }
			if(x > last_pos)
				last_pos = x;
		}
	}

	ll pos_output_given = 0;
	ll pos;
	for(pos = 1; pos <= last_pos; pos++){

		if(s[a[pos]] == ""){

			if(pos > pos_output_given){
				cout << "a";
				pos_output_given++;
			}

		}else{

			ll alpha = ( (ll) s[a[pos]].length() ) - 1;
			ll str_len = (ll) s[a[pos]].length();
			if(pos + alpha > pos_output_given){
				ll n = pos + alpha - pos_output_given;
				string o = s[a[pos]].substr(str_len - n, n);
				cout << o;
				pos_output_given = pos + alpha;
			}

		}

		//cout << "pos=" << pos << " pos_output_given=" << pos_output_given << endl;
	}

	return 0;
}