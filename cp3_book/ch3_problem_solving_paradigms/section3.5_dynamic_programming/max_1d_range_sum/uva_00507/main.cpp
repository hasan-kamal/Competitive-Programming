/* Kadane's algorithm */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, T = 0;
	cin >> N;

	int n;
	vi a;
	while(N--){
		cin >> n;
		n--;

		a = vi(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		
		vi ans(n, INT_MIN), b(n, INT_MIN), b_s(n, INT_MIN);
		vector< pair<int, int> > ranges(n);
		ans[0] = b[0] = a[0];
		b_s[0] = 0;
		ranges[0] = make_pair(0, 0);
		for(int i = 0; i < n - 1; i++){
			b[i + 1] = a[i + 1] + (b[i] >= 0 ? b[i] : 0);
			if(b[i] >= 0)
				b_s[i + 1] = b_s[i];
			else
				b_s[i + 1] = i + 1;
			ans[i + 1] = max(ans[i], b[i + 1]);
			if(ans[i] > b[i + 1])
				ranges[i + 1] = ranges[i];
			else if(ans[i] < b[i + 1]){
				ranges[i + 1] = make_pair(b_s[i + 1], i + 1);
			}else{
				// ans[i] == b[i + 1]
				if(ranges[i].second - ranges[i].first >= i + 1 - b_s[i + 1])
					ranges[i + 1] = ranges[i];
				else
					ranges[i + 1] = make_pair(b_s[i + 1], i + 1);
			}
		}

		int i = ranges[n - 1].first, j = ranges[n - 1].second;
		cout << (ans[n - 1] <= 0 ? "Route " + to_string(++T) + " has no nice parts" : "The nicest part of route " + to_string(++T) + " is between stops " + to_string(i + 1) + " and " + to_string(j + 2)) << endl;
	}

	return 0;
}