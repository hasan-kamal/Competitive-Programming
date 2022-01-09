#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#define DP_SIZE 1000000
#define INF 1000000000
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

double dp[DP_SIZE];
vii locs;

double dist(ii p1, ii p2){
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double top_down(int mask, int n){
	if(dp[mask] > 0.0)
		return dp[mask];
	if(mask == 0)
		return 0.0;

	int i = 2 * n - 1;
	while(i >= 0 && (( (~mask) >> i) & 1))
		i--;
	assert(i >= 0);

	double best_ans = INF;
	for(int j = i - 1; j >= 0; j--){
		if((mask >> j) & 1){
			double ans = 0.0;
			ans += dist(locs[i], locs[j]);
			if(ans > best_ans)
				continue;
			int new_mask = mask;
			new_mask = new_mask & (~(1 << j));
			new_mask = new_mask & (~(1 << i));
			ans += top_down(new_mask, n);
			best_ans = min(best_ans, ans);
		}
	}
	dp[mask] = best_ans;
	return dp[mask];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int t = 1;
	string name;
	do{
		cin >> n;
		if(!n)
			break;
		memset(dp, -1.0, sizeof(double) * (1 << (2 * n)));
		locs = vii(2 * n);
		for(int i = 0; i < 2 * n; i++){
			cin >> name >> locs[i].first >> locs[i].second;
		}
		printf("Case %d: %.2lf\n", t, top_down( (1 << (2 * n)) - 1, n));
		t++;
	}while(n);

	return 0;
}