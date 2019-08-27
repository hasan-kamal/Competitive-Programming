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

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		// 4,8,15,16,23,42
		if(a[i] == 4)
			a[i] = 0;
		else if(a[i] == 8)
			a[i] = 1;
		else if(a[i] == 15)
			a[i] = 2;
		else if(a[i] == 16)
			a[i] = 3;
		else if(a[i] == 23)
			a[i] = 4;
		else if(a[i] == 42)
			a[i] = 5;
	}

	vvi c(n, vi(6, 0));
	if(a[n - 1] == 5)
		c[n - 1][a[n - 1]]++;
	for(int i = n - 2; i >= 0; i--){
		c[i] = c[i + 1];
		if(a[i] == 5)
			c[i][5]++;
		else if(c[i + 1][a[i] + 1] > 0){
			c[i][a[i] + 1]--;
			c[i][a[i]]++;
		}
	}

	cout << n - (c[0][0] * 6) << endl;

	return 0;
}