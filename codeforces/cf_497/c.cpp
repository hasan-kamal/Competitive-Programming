/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<ii> sii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vii a = vii(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin(), a.end());
	sii picked;
	int largest = a[n - 1].first;
	picked.insert(make_pair(largest, n - 1));
	int smallest_l_index = n - 1;
	for(int i = n - 2; i >= 0; i--){
		if(a[i].first != largest)
			break;
		picked.insert(make_pair(largest, i));
		smallest_l_index = i;
	}

	int ans = 0;
	for(int i = smallest_l_index - 1; i >= 0; i--){
		ii mx = *picked.rbegin();

		if(a[i].first < mx.first){
			picked.erase(mx);
			picked.insert(make_pair(a[i].first, a[i].second));
			ans++;
		}else{
			// just use this to swap
			picked.insert(make_pair(a[i].first, a[i].second));
		}
		
	}

	cout << ans;

	return 0;
}