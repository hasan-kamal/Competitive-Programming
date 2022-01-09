#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<double, double> dd;
typedef vector<dd> vdd;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double d;

	int t = 0;
	while(cin >> n >> d){
		if(!n && !d)
			return 0;

		vdd intervals(n);
		int x, y;
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			intervals[i] = make_pair(x + sqrt((double)d * d - y * y), x - sqrt((double)d * d - y * y));
			if(y > d){
				ans = -1;
			}
		}

		sort(intervals.begin(), intervals.end());

		if(ans >= 0){
			double covered = INT_MIN;
			for(int i = 0; i < n; i++){
				if(intervals[i].second > covered){
					covered = intervals[i].first;
					ans++;
				}
			}
		}

		t++;
		cout << "Case " << t <<": " << ans << endl;
	}

	return 0;
}