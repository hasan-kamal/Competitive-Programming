/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	int n, a, b, c;
	cin >> n >> b >> a;

	int ans = 0;
	vi t = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> t[i];

	c = 0;
	for(int i = 1; i <= n; i++){
		if(t[i] == 1){

			if(b > 0)
				b--;
			else if(a > 0){
				a--;
				c++;
			}else if(c > 0){
				c--;
			}else
				ans++;

		}else{

			if(a > 0)
				a--;
			else
				ans += 2;

		}
	}

	cout << ans;

	return 0;
}