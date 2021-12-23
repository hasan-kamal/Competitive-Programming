#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef set<char> sc;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string a, b;
	cin >> a;
	cin >> b;

	int ans = 0;
	if(n % 2 == 1 && a[n / 2] != b[n / 2])
		ans++;

	for(int i = 0; i < n; i++){
		if(n - 1 - i <= i)
			continue;

		sc s = sc();
		s.insert(a[i]);
		s.insert(a[n - 1 - i]);
		s.insert(b[i]);
		s.insert(b[n - 1 - i]);

		if(s.size() == 1)
			continue;
		if(s.size() == 2){
			if(b[i] != b[n - 1 - i]){
				if(a[i] == a[n - 1 - i])
					ans++;
				else
					continue;
			}else{
				if(a[i] != a[n - 1 - i])
					ans++;
				else
					continue;
			}

		}else if(s.size() == 3){
			if(a[i] == a[n - 1 - i])
				ans += 2;
			else
				ans += 1;
		}else if(s.size() == 4)
			ans += 2;
	}

	cout << ans;

	return 0;
}