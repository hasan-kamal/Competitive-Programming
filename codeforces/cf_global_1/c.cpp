#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef set<int> si;
typedef map<int, int> mii;

// int gcd(int a, int b){
// 	if(b == 0)
// 		return a;
// 	return gcd(b, a % b);
// }

// int f(int a){
// 	int best = -1, best_val = -1;
// 	for(int b = 1; b < a; b++){
// 		int t = gcd(a^b, a&b);
// 		if(t > best)
// 			best_val = b;
// 		best = max(best, t);
// 	}
// 	return best;
// }

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int store[] = {-1,  1,  1,  5,  1,  21,  1,  85,  73,  341,  89,  1365,  1,  5461,  4681,  21845,  1,  87381,  1,  349525,  299593,  1398101,  178481,  5592405,  1082401};
	
	si s;
	int val = 2;
	mii ansval;
	mii p;
	for(int i = 1; i < 26; i++){
		p[i] = val;
		s.insert(val - 1);
		ansval[val -1] = store[i - 1];
		val *= 2;
	}
	
	int q;
	cin >> q;
	int a;
	for(int i = 0; i < q; i++){
		cin >> a;
		int ans;
		if(s.find(a) == s.end()){
			int msb = -1;
			for(int dig = 30; dig >= 0; dig--){
				if( (a >> dig) & 1 ){
					msb = dig;
					break;
				}
			}
			ans = p[msb + 1] - 1;
		}else
			ans = ansval[a];
		cout << ans << endl;
	}

	return 0;
}