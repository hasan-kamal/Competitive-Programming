#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define NEG_INF (-1000000)
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int K, C, M;
	vvi a, memo;

	while(N--){
		cin >> M >> C;
		int K;
		a = vvi(C, vi());
		for(int i = 0; i < C; i++){
			cin >> K;
			int temp;
			for(int j = 0; j < K; j++){
				cin >> temp;
				a[i].push_back(temp);
			}
		}

		// initialize DP
		vvi max_spend = vvi(C, vi(M + 1, -1));
		for(int amt = 0; amt <= M; amt++){
			int largest_smaller_than_amt = NEG_INF;
			for(int p : a[C - 1])
				if(p <= amt && p > largest_smaller_than_amt)
					largest_smaller_than_amt = p;
			max_spend[C - 1][amt] = largest_smaller_than_amt;
		}

		// fill table
		for(int i = C - 2; i >= 0; i--){
			for(int amt = 0; amt <= M; amt++){
				int largest_smaller_than_amt = NEG_INF;
				for(int p : a[i]){
					if(amt >= p && max_spend[i + 1][amt - p] != NEG_INF){
						max_spend[i][amt] = 1;
						max_i = max(max_i, i);
						break;
					}
				}
				for(int i = 0; i <= max_i; i++)
					max_spend[i][amt] = 1;
			}
		}

		int ans = -1;
		for(int i = M; i >= 0; i--)
			if(max_spend[0][i]){
				ans = i;
				break;
			}
		cout << ((ans == -1) ? "no solution" : to_string(ans)) << endl;
	}

	return 0;
}