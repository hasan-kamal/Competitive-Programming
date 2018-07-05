/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int maximum(int a, int b){
	return a > b ? a : b;
}

bool is_pal(string s){
	int n = s.length();
	for(int i = 0; i < n; i++)
		if(s[i] != s[n - 1 - i])
			return false;
	return true;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int ans = 0;
	int n = s.length();
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(!is_pal(s.substr(i, j - i + 1)))
				ans = maximum(ans, j - i + 1);
		}
	}

	cout << ans;

	return 0;
}