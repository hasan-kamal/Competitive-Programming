#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vi a = vi(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	ll sum = 0, prev = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];

		cout << (sum / m - prev / m) << " ";

		prev = sum;
	}

	return 0;
}