#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int 	ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y;	
	cin >> n >> x >> y;

	string s;
	cin >> s;

	int ans = 0;
	for(int i = 0; i < x; i++){
		if(i == y){
			if(s[n - 1 - i] != '1')
				ans++;
		}else{
			if(s[n - 1 - i] != '0')
				ans++;
		}
	}
	cout << ans;

	return 0;
}