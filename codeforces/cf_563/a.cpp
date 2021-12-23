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

	vi a(2 * n);
	for(int i = 0; i < 2 * n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	ll left = 0;
	ll right = 0;
	for(int i = 0; i < n; i++)
		left += a[i];

	for(int i = n; i < 2 * n; i++)
		right += a[i];

	if(left == right){
		cout << -1;
		return 0;
	}

	for(int i = 0; i < 2 * n; i++)
		cout << a[i] << " ";

	return 0;
}