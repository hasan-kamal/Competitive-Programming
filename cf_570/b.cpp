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

	int q;
	cin >> q;

	int n, k;
	while(q--){
		cin >> n >> k;

		vi a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		int min_ = *min_element(a.begin(), a.end());
		int max_ = *max_element(a.begin(), a.end());
		if(max_ - k > min_ + k){
			cout << -1 << endl;
			continue;
		}

		cout << min_ + k << endl;
	}

	return 0;
}