/*

@author hasankamal

*/

#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

#define M 3001
typedef pair<int, int> ii;
short dp[M][M];
short nxt[M][M];
int c[M];

int main(){

	freopen("fibsubseq.in", "r", stdin);
	freopen("fibsubseq.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m;
	cin >> m;

	for(int i = 0; i < m; i++){
		cin >> c[i];
	}

	// for(int i = 0; i < M / 2; i++){
	// 	for(int j = 0; j < M; j++)
	// 		nxt[i][j] = -1;
	// }
	
	ii best_ij = make_pair(-1, -1);
	map<int, int> earliest_index;
	for(int i = m - 1; i >= 0; i--){
		earliest_index.clear();
		for(int j = m - 1; j >= i + 1; j--){
			if(earliest_index.find(c[i] + c[j]) == earliest_index.end()){
				dp[i][j] = 2;
				nxt[i][j] = -1;
			}else{
				int k = earliest_index[c[i] + c[j]];
				dp[i][j] = dp[j][k] + 1;
				nxt[i][j] = k;
			}
			earliest_index[c[j]] = j;

			if(best_ij.first == -1){
				best_ij = make_pair(i, j);
			}else if(dp[i][j] > dp[best_ij.first][best_ij.second]){
				best_ij = make_pair(i, j);
			}
		}
	}
	if(best_ij.first == -1){
		cout << 1 << endl;
		cout << c[0] << endl;
	}else{
		cout << dp[best_ij.first][best_ij.second] << endl;
		int i = best_ij.first;
		int j = best_ij.second;
		cout << c[i] << " " << c[j] << " ";
		while(nxt[i][j] != -1){
			cout << c[nxt[i][j]] << " ";
			int temp = j;
			j = nxt[i][j];
			i = temp;
		}
		cout << endl;
	}

	return 0;
}