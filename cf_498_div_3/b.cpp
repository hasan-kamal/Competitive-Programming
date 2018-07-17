#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vii a = vii(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i + 1;
	}

	sort(a.rbegin(), a.rend());

	vii another = vii(k);
	int sum = 0;
	for(int i = 0; i < k; i++){
		another[i].first = a[i].second;
		another[i].second = a[i].first;
		sum += a[i].first;
	}

	sort(another.begin(), another.end());

	cout << sum << endl;
	int prev = 0;
	for(int i = 0; i < k - 1; i++){
		cout << another[i].first - prev << " ";
		prev = another[i].first;
	}
	cout << n - prev;


	return 0;
}