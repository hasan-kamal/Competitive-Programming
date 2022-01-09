#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi> 		vvi;
typedef vector<vvi> 	vvvi;

vvi a_cost, b_cost;
vvvi dp;
int n;

int compute(int site_index, int t1, int t2){
	int &ans = dp[site_index][t1][t2];
	if(ans >= 0 || ans == INT_MIN)
		return ans;

	int m_i = a_cost[site_index].size() - 1;
	ans = INT_MAX;
	for(int i = 0; i <= m_i; i++){
		// send i samples to A, m_i - i samples to B
		if(i <= t1 && m_i - i <= t2){
			int future_cost = 0;
			if(site_index < n - 1)
				future_cost = compute(site_index + 1, t1 - i, t2 - m_i + i);
			if(future_cost == INT_MIN)
				continue;
			ans = min(ans, a_cost[site_index][i] + b_cost[site_index][m_i - i] + future_cost);
		}
	}
	if(ans == INT_MAX)
		ans = INT_MIN;
	return ans;
}

void print_choice(int site_index, int t1, int t2){
	int &ans = dp[site_index][t1][t2];
	
	int m_i = a_cost[site_index].size() - 1;
	for(int i = 0; i <= m_i; i++){
		// send i samples to A, m_i - i samples to B
		if(i <= t1 && m_i - i <= t2){
			int future_cost = 0;
			if(site_index < n - 1)
				future_cost = dp[site_index + 1][t1 - i][t2 - m_i + i];
			if(future_cost == INT_MIN)
				continue;
			if(a_cost[site_index][i] + b_cost[site_index][m_i - i] + future_cost == ans){
				cout << i;
				if(site_index < n - 1){
					cout << " ";
					print_choice(site_index + 1, t1 - i, t2 - m_i + i);
				}
				break;
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t1, t2, m, temp;
	while(cin >> t1 >> t2){
		if(!t1 && !t2)
			break;

		cin >> n;
		a_cost = vvi(n, vi());
		b_cost = vvi(n, vi());
		for(int i = 0; i < n; i++){
			cin >> m;
			a_cost[i].push_back(0);
			for(int j = 0; j < m; j++){
				cin >> temp;
				a_cost[i].push_back(temp);
			}
			b_cost[i].push_back(0);
			for(int j = 0; j < m; j++){
				cin >> temp;
				b_cost[i].push_back(temp);
			}
		}

		dp = vvvi(n, vvi(t1 + 1, vi(t2 + 1, -1)));
		compute(0, t1, t2);

		cout << dp[0][t1][t2] << endl;
		print_choice(0, t1, t2);
		cout << endl << endl;
	}

	return 0;
}