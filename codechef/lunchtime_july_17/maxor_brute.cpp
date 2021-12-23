/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int max(int a, int b){
	return a > b ? a : b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		
		vi a = vi(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		ll ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if((a[i] | a[j]) <= max(a[i], a[j]))
					ans++;
			}
		}
		cout << ans << endl;
	}		

	return 0;
}