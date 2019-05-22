/* Divide and Conquer algorithm */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

iii max_1d_sum(vi &a, int low, int high){
	if(low == high){
		return make_pair(a[low], make_pair(low, high));
	}
	int mid = low + (high - low) / 2;
	iii l = max_1d_sum(a, low, mid);
	iii r = max_1d_sum(a, mid + 1, high);

	int l_ = mid, l_sum = 0, l_max = -1;
	for(int i = mid; i >= low; i--){
		l_sum += a[i];
		if(l_sum >= l_max){
			l_max = l_sum;
			l_ = i;
		}
	}

	int r_ = mid + 1, r_sum = 0, r_max = -1;
	for(int i = mid + 1; i <= high; i++){
		r_sum += a[i];
		if(r_sum >= r_max){
			r_max = r_sum;
			r_ = i;
		}
	}

	iii cross = make_pair(l_max + r_max, make_pair(l_, r_));
	vector< pair<iii, int> > options;
	options.push_back(make_pair( make_pair(l.first, make_pair(l.second.second - l.second.first, -l.second.first)) , 0));
	options.push_back(make_pair( make_pair(r.first, make_pair(r.second.second - r.second.first, -r.second.first)) , 1));
	options.push_back(make_pair( make_pair(cross.first, make_pair(cross.second.second - cross.second.first, -cross.second.first)) , 2));
	sort(options.rbegin(), options.rend());
	if(options[0].second == 0)
		return l;
	else if(options[0].second == 1)
		return r;
	else
		return cross;
}

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
		
		iii ans = max_1d_sum(a, 0, n - 1);
		cout << (ans.first <= 0 ? "Route " + to_string(++T) + " has no nice parts" : "The nicest part of route " + to_string(++T) + " is between stops " + to_string(ans.second.first + 1) + " and " + to_string(ans.second.second + 2)) << endl;
	}

	return 0;
}