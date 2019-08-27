#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <map>
#include <cmath>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	bool max_positive = true, min_positive = true;
	vi max_(n + 1), min_(n + 1);
	for(int i = 1; i <= n; i++){
		vll values;
		values.push_back(min_[i - 1] * a[i]);
		mp[i][min_[i - 1] * a[i]] = a[i];
		values.push_back(min_[i - 1] * (-a[i] - 1));
		mp[i][min_[i - 1] * (-a[i] - 1)] = (-a[i] - 1);
		values.push_back(max_[i - 1] * a[i]);
		mp[i][max_[i - 1] * a[i]] = a[i];
		values.push_back(max_[i - 1] * (-a[i] - 1));
		mp[i][max_[i - 1] * (-a[i] - 1)] = (-a[i] - 1);
		sort(values.begin(), values.end());
		max_[i] = sign(values[3]);
		min_[i] = sign(values[0]);

		if(max_positive && min_positive){
			if(a[i] >= 0){
				max_[i] = a[i];
				min_[i] = -a[i] - 1;
			}else{
				max_[i] = -a[i] - 1;
				min_[i] = a[i];
			}
		}else if(!max_positive && min_positive){

		}else if(max_positive && !min_positive){
			
		}else{

		}

	}

	ll prod = max_[n];
	vi ans(n + 1);
	for(int i = n; i >= 1; i--){
		ans[i] = mp[i][prod];
		if(ans[i] != 0)
			prod /= ans[i];
		else
			prod = max_[i - 1];
	}
	

	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}