#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
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


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		vi a(n);
		vi b(3, 0);
		for(int i = 0; i < n; i++){
			cin >> a[i];
			b[a[i] % 3]++;
		}
		int ans = b[0] + min(b[1], b[2]) + (max(b[1], b[2]) - min(b[1], b[2])) / 3;
		cout << ans << endl;
	}		

	return 0;
}