#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	ll sum = 0;
	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}

	if(x > sum){
		cout << n - 1;
		return 0;
	}

	if(x == sum){
		cout << n;
		return 0;
	}

	sort(a.begin(), a.end());
	int count = 0;
	int i = 0;
	while(x > 0){
		x -= (a[i]);
		if(x >= 0){
			count++;
		}else{
			break;
		}
		i++;
	}

	cout << count;

	return 0;
}