#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi count(26, 0);
	string s;
	for(int i = 0; i < n; i++){
		cin >> s;
		count[s[0] - 'a']++;
	}

	ll ans = 0;
	for(int i = 0; i < 26; i++){
		if(count[i] <= 2)
			continue;
		int l = count[i] / 2;
		int r = count[i] - l;
		ans = ans + ((l * (l - 1)) / 2);
		ans = ans + ((r * (r - 1)) / 2);
	}
	cout << ans;

	return 0;
}