/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi s(n);
	for(int i = 0; i < n; i++)
		cin >> s[i];

	vi c(n);
	for(int i = 0; i < n; i++)
		cin >> c[i];

	vi next_best(n, -1);
	for(int i = 0; i < n; i++){
		int best_cost = INT_MAX;
		for(int j = i + 1; j < n; j++){
			if(s[i] < s[j]){
				if(c[j] < best_cost)
					best_cost = c[j];
			}
		}
		next_best[i] = (best_cost == INT_MAX) ? -1 : best_cost;
	}

	int best_ans = INT_MAX;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(s[i] >= s[j])
				continue;
			if(next_best[j] == -1)
				continue;
			if(c[i] + c[j] + next_best[j] < best_ans)
				best_ans = c[i] + c[j] + next_best[j];
		}
	}

	if(best_ans == INT_MAX)
		cout << "-1";
	else
		cout << best_ans;

	return 0;
}