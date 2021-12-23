#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		vi a(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		int min_ = a[n - 1];
		int ans = 0;
		for(int i = n - 2; i >= 0; i--){
			if(a[i] > min_)
				ans++;
			min_ = min(min_, a[i]);
		}
		cout << ans << endl;
	}

	return 0;
}