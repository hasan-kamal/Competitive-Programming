#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#define INF 1000000000
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int bsearch(vi &a, int s, int e, int p){
	int lo = s;
	int hi = e;
	while(lo < hi){
		int mid = lo + (hi - lo) / 2;
		if(a[mid] >= p)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n), l(n), r(n);
	int mx = -1;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mx = max(a[i], mx);
	}
	
	l[0] = a[0];
	for(int i = 1; i < n; i++){
		l[i] = max(l[i - 1], a[i]);
	}

	r[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--){
		r[i] = max(r[i + 1], a[i]);
	}
	reverse(r.begin(), r.end());


	int k = INF;
	for(int i = 0; i < n; i++){
		if(a[i] == mx)
			continue;

		int j_l = bsearch(l, 0, n - 1, a[i]);
		int j_r = n - 1 - bsearch(r, 0, n - 1, a[i]);
		// cout << i << " " << j_l << " " << j_r << endl;

		if(i != j_l){
			int k_l = a[i] / abs(i - j_l);
			k = min(k, k_l);
		}

		if(i != j_r){
			int k_r = a[i] / abs(i - j_r);
			k = min(k, k_r);
		}
	}
	if(k == INF)
		k = mx / (n - 1);
	cout << k;

	return 0;
}