#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector< pair<double, double> > vdd;

int interval_color(vdd &intervals, double L, double R){
	sort(intervals.begin(), intervals.end());
	
	double covered = L;
	int i = 0;
	int ans = 0;

	while(covered < R && i < intervals.size()){
		if(intervals[i].first > covered)
			return -1;

		int best_interval = i;
		while(intervals[i].first <= covered){
			if(intervals[i].second >= intervals[best_interval].second)
				best_interval = i;
			i++;
			if(i >= intervals.size())
				break;
		}

		if(intervals[best_interval].second <= covered)
			return -1;

		covered = intervals[best_interval].second;
		ans++;
	}

	return covered >= R ? ans : -1;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	double l, w;
	while(cin >> n >> l >> w){
		vdd intervals(n);
		for(int i = 0; i < n; i++){
			double pos, r;
			cin >> pos >> r;
			double dx = r < w / 2.0 ? 0.0 : sqrt(r * r - w * w / 4.0);
			intervals[i].first = pos - dx;
			intervals[i].second = pos + dx;
		}
		cout << interval_color(intervals, 0, l) << endl;;
	}

	return 0;
}