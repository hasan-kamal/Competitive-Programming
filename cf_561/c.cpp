#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll ans = 0;
	for(int i = 0; i < n - 1; i++){
		int x = a[i];
		// assume x <= y
		if(x >= 0){
			// both +ve
			// all y in range [x, 2x]
			vi::iterator start = lower_bound(a.begin(), a.end(), x);
			if(start <= (a.begin() + i))
				start = a.begin() + i + 1;
			vi::iterator end = upper_bound(a.begin(), a.end(), 2 * x);
			if(start <= end)
				ans = ans + (end - start);
		}else{
			// both -ve
			// all y in range [x, x / 2]
			vi::iterator start = lower_bound(a.begin(), a.end(), x);
			if(start <= (a.begin() + i))
				start = a.begin() + i + 1;
			vi::iterator end = upper_bound(a.begin(), a.end(), x % 2 == 0 ? x / 2 : (x / 2) - 1);
			if(start <= end)
				ans = ans + (end - start);

			// y +ve

			// abs(x) <= abs(y)
			// all y in range [-x, -2x]
			start = lower_bound(a.begin(), a.end(), -1 * x);
			if(start <= (a.begin() + i))
				start = a.begin() + i + 1;
			end = upper_bound(a.begin(), a.end(), -2 * x);
			if(start <= end)
				ans = ans + (end - start);

			// abs(x) > abs(y)
			// all y in range [-x/2, -x - 1]
			start = lower_bound(a.begin(), a.end(), (-1 * x) % 2 == 0 ? (-1 * x) / 2 : ((-1 * x) / 2) + 1);
			if(start <= (a.begin() + i))
				start = a.begin() + i + 1;
			end = upper_bound(a.begin(), a.end(), (-1 * x) - 1);
			if(start <= end)
				ans = ans + (end - start);			
		}
	}

	cout << ans;

	return 0;
}