#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int	ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vi flips;
	int c;
	for(int i = 1; i <= n; i++){
		if(i >= k){
			c = 0;
			flips.push_back(c);
			continue;
		}
		
		double c_ = log2(k / (double)i);
		c = 1 + (int)c_;
		if(c > 0 && pow(2, c - 1) >= k / (double)i)
			c--;
		flips.push_back(c);
	}

	
	ll num = 0;
	ll f_max = *max_element(flips.begin(), flips.end());
	for(int flip : flips){
		num += pow(2, f_max - flip);
	}
	double ans = num / ((double)pow(2, f_max) * n);
	printf("%.13lf", ans);

	return 0;
}