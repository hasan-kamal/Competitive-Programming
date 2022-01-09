#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi> 		vvi;

vi dp, time_;
int n, m;

int f(int t){
	if(dp[t] >= -1)
		return dp[t];
	if(t == 0){
		dp[t] = 0;
		return dp[t];
	}
	if(t < min(n, m)){
		dp[t] = -1;
		return -1;
	}
	if(t - n >= 0 && f(t - n) != -1)
		dp[t] = max(dp[t], 1 + f(t - n));
	if(t - m >= 0 && f(t -m) != -1)
		dp[t] = max(dp[t], 1 + f(t - m));
	if(dp[t] == INT_MIN)
		dp[t] = -1;
	return dp[t];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	while(cin >> m >> n >> t){
		dp = vi(t + 1, INT_MIN);
		time_ = vi(t + 1, 0);

		f(t);

		int t_ = t;
		while(t_ >= 0 && f(t_) == -1)
			t_--;
		cout << (t_ >= 0 ? dp[t_] : 0);
		if(t_ < t)
			cout << " " << t - t_;
		cout << endl;
	}


	return 0;
}