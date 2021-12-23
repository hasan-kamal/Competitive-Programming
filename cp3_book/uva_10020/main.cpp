#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> 	ii;
typedef vector<ii> vii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int m;
	while(t--){
		vii intervals;
		cin >> m;

		int l, r;
		while(cin >> l >> r){
			if(!l && !r)
				break;
			intervals.push_back(make_pair(l, r));
		}

		sort(intervals.begin(), intervals.end());
		vii sel_intervals;
		int ans = 0, i = 0, x = 0;

		while(x < m){
			if(intervals[i].first > x){
				ans = -1;
				break;
			}

			int best_i = i;
			while(intervals[i].first <= x){
				if(intervals[i].second > intervals[best_i].second)
					best_i = i;
				i++;
				if(i >= intervals.size())
					break;
			}

			if(intervals[best_i].second <= x){
				ans = -1;
				break;
			}

			x = intervals[best_i].second;
			sel_intervals.push_back(intervals[best_i]);
			ans++;
		}

		if(ans == -1){
			cout << 0 << endl << endl;
			continue;
		}

		cout << ans << endl;
		for(ii interval : sel_intervals)
			cout << interval.first << " " << interval.second << endl;
		cout << endl;
	}

	return 0;
}