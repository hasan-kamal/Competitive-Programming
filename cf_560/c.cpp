#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int 	ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vi del(n, 0);

	int ans = 0;
	for(int i = 0; i < n;){
		int del_ = i + 1;
		while(del_ < n && s[del_] == s[i]){
			ans++;
			del[del_] = 1;
			del_++;
		}
		i = del_ + 1;
	}

	if((n - ans) % 2 != 0){
		// remove last
		int j = -1;
		for(int i = n - 1; i >= 0; i--)
			if(del[i] == 0){
				j = i;
				ans++;
				break;
			}
		del[j] = 1;
	}

	cout << ans << endl;
	for(int i = 0; i < n; i++){
		if(del[i] == 0)
			cout << s[i];
	}

	return 0;
}