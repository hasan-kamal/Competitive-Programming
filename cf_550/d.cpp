#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	vi count(200005, 0);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		count[a[i]]++;
	}

	int mode = a[0];
	for(int i = 0; i < n; i++){
		if(count[a[i]] > count[mode]){
			mode = a[i];
		}
	}

	int ans = 0;
	int ind_mode = -1;
	for(int i = 0; i < n; i++){
		if(a[i] != mode)
			ans++;
		else
			ind_mode = i;
	}

	cout << ans << endl;

	for(int i = ind_mode + 1; i < n; i++){
		if(a[i] == mode)
			continue;
		if(a[i] > mode)
			cout << "2 " << i + 1 << " " << i << endl;
		else
			cout << "1 " << i + 1 << " " << i << endl;
	}

	for(int i = ind_mode - 1; i >= 0; i--){
		if(a[i] == mode)
			continue;
		if(a[i] > mode)
			cout << "2 " << i + 1 << " " << i + 2 << endl;
		else
			cout << "1 " << i + 1 << " " << i + 2 << endl;
	}

	return 0;
}