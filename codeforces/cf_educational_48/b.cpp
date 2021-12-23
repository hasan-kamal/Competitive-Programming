#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;	

	string s, t;
	cin >> s >> t;

	vi ans = vi(n, 0);
	if(n >= m){
		for(int i = m - 1; i < n; i++){
			if(s[i] == t[m - 1]){
				if(t.compare(s.substr(i - m + 1, m)) == 0){
					if(i - 1 >= 0)
						ans[i] = ans[i - 1] + 1;
					else
						ans[i] = 1;
				}else{
					if(i - 1 >= 0)
						ans[i] = ans[i - 1];
					else
						ans[i] = 0;
				}
			}else{
				if(i - 1 >= 0)
					ans[i] = ans[i - 1];
				else
					ans[i] = 0;
			}
		}
	}

	// for(int i = 0; i < n; i++)
	// 	cout << ans[i] << " ";
	// cout << endl;


	int l, r;
	while(q--){
		cin >> l >> r;

		if(r - l + 1 < m){
			cout << 0 << endl;
			continue;
		}

		if(l == 1)
			cout << ans[r - 1] << endl;
		else
			cout << ans[r - 1] - ans[l - 2 + m - 1] << endl;
	}

	return 0;
}