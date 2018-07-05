/*

@author hasankamal

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vi;

bool exists(vi &perf, int lo, int hi, int val){
	if(lo < hi){
		int mid = lo + (hi - lo) / 2;
		if(val <= perf[mid])
			return exists(perf, lo, mid, val);
		else
			return exists(perf, mid + 1, hi, val);
	}else
		return perf[lo] == val;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	vi perf;
	for(int i = 0; i <= 1000; i++)
		perf.push_back(i * i);

	sort(a.begin(), a.end());

	for(int i = a.size() - 1; i >= 0; i--){
		if(!exists(perf, 0, perf.size() - 1, a[i])){
			cout << a[i];
			break;
		}
	}

	return 0;
}