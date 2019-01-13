#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(2 * n);
	for(int i = 0; i < 2 * n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	long long int ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i];

	cout << ans;

	return 0;
}