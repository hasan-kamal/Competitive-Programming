#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int	ll;

int mpow(int base, int exp){
	int ans = 1;
	while(exp--)
		ans *= base;
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, k;
	cin >> m >> k;

	if(k > mpow(2, m) - 1){
		cout << "-1";
		return 0;
	}

	if(m == 0 && k == 0){
		cout << "0 0";
		return 0;
	}

	if(m == 1 && k == 1){
		cout << "-1";
		return 0;
	}

	if(m == 1 && k == 0){
		cout << "0 1 1 0";
		return 0;
	}

	// m >= 2 holds
	int n = mpow(2, m) - 1;

	for(int i = 0; i <= n; i++){
		if(i == k)
			continue;
		cout << i << " ";
	}
	cout << k << " ";
	for(int i = n; i >= 0; i--){
		if(i == k)
			continue;
		cout << i << " ";
	}
	cout << k << " ";

	return 0;
}