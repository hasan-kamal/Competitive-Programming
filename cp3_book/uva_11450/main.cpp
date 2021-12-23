#include <iostream>
#include <vector>
#include <climits>
#define NEG_INF (-1000000)
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi memo;
vvi a;
int M, C;

int mp(int i, int amt){
	if(memo[i][amt] != -1)
		return memo[i][amt];
	int ans = NEG_INF;
	for(int j = 0; j < a[i].size(); j++){
		if(amt < a[i][j])
			continue;
		if(i + 1 < C){
			int future_cost = mp(i + 1, amt - a[i][j]);
			if(future_cost == NEG_INF)
				continue;
			ans = max(ans, a[i][j] + future_cost);
		}else{
			ans = max(ans, a[i][j]);
		}
	}
	memo[i][amt] = ans;
	return memo[i][amt];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	while(N--){
		cin >> M >> C;
		int K;
		a = vvi(C, vi());
		memo = vvi(C, vi(M + 1, -1));
		for(int i = 0; i < C; i++){
			cin >> K;
			int temp;
			for(int j = 0; j < K; j++){
				cin >> temp;
				a[i].push_back(temp);
			}
		}

		int ans = mp(0, M);
		cout << ((ans == NEG_INF) ? "no solution" : to_string(ans)) << endl;
	}

	return 0;
}