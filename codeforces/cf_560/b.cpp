#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int 	ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int day = 1;
	int pos = 0;
	int ans = 0;
	while(pos < n){
		if(a[pos] >= day){
			ans++;
			day++;
			pos++;
		}else{
			pos++;
		}
	}
	cout << ans;

	return 0;
}