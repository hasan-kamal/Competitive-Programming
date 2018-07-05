/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	int n, a, b, c;
	cin >> n >> a >> b >> c;

	int ans = 0;
	n--;
	int state = 0;
	while(n--){
		if(state == 0){
			if(a < b){
				ans += a;
				state = 1;
			}else{
				ans += b;
				state = 2;
			}
		}else if(state == 1){
			if(a < c){
				ans += a;
				state = 0;
			}else{
				ans += c;
				state = 2;
			}
		}else if(state == 2){
			if(b < c){
				ans += b;
				state = 0;
			}else{
				ans += c;
				state = 1;
			}
		}
	}

	cout << ans;

	return 0;
}