/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#define N 1000
#define M 1000000007
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int num_bits(int x){
	int count = 0;
	for(int i = 30; i >= 0; i--)
		if((x >> i) & 1)
			count++;
	return count;
}

int C[N + 1][N + 1];
void preprocess(){
	for(int i = 0; i <= N; i++){
		C[i][0] = 1;
		C[i][i] = 1;
	}

	for(int i = 2; i <= N; i++){
		for(int j = 1; j < i; j++){
			C[i][j] = ( C[i - 1][j] + C[i - 1][j - 1] ) % M;
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vi dp(N + 1);
	dp[1] = 0;
	for(int i = 2; i <= 1000; i++){
		dp[i] = dp[num_bits(i)] + 1;
	}

	preprocess();

	string s;
	cin >> s;

	int k;
	cin >> k;

	if(k == 0){
		cout << 1;
		return 0;
	}

	if(k == 1){
		cout << s.length() - 1;
		return 0;
	}

	ll ans = 0;
	int alpha = s.length();
	for(int i = 1; i <= 1000; i++){
		if(dp[i] == k - 1){
			// count how many numbers <= n exist s.t. they reduce to i in one step
			// # of x such that x has i bits set and x <= n

			int num_ones = 0;
			for(int k = 1; alpha - k >= 1; k++){
				if(s[k - 1] == '1'){
					if( (alpha - k >= i - num_ones) && (i - num_ones >= 0) )
						ans = ( ans + ( C[alpha - k][i - num_ones] % M ) ) % M;					
					// cout << i << " :: " << ans << endl;
					num_ones++;
				}
			}

			int to_add = 0;

			// check last bit
			if(s[alpha - 1] == '1'){
				num_ones++;
				if(num_ones == i)
					to_add = 1;	// let last bit be 1
				else if(num_ones - 1 == i)
					to_add = 1; // can make last bit 0
			}else{
				// last bit is 0
				if(num_ones == i)
					to_add = 1; // the number itself as it is

			}

			// cout << i << " -- " << ans << endl << endl;
			ans = ( ans + ( to_add % M ) ) % M; 
		}
	}

	cout << ans;

	return 0;
}