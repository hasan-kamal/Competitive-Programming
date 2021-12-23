#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int ans = INT_MAX;
	int m = *max_element(a.begin(), a.end());
	for(int val = 0; val <= m; val++){
		vi steps;
		for(int i = 0; i < n; i++){
			if(a[i] < val){
				steps.push_back(INT_MAX);
				continue;
			}
			int v = a[i];
			int c = 0;
			while(v != val && v != 0){
				c++;
				v /= 2;
			}
			if(v == val)
				steps.push_back(c);
			else
				steps.push_back(INT_MAX);
		}
		sort(steps.begin(), steps.end());
		int count = 0;
		for(int i = 0; i < k; i++){
			if(count != INT_MAX)
				count += steps[i];
			if(steps[i] == INT_MAX)
				count = INT_MAX;
		}
		ans = min(ans, count);
	}

	cout << ans;
	
	return 0;
}