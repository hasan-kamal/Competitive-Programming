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

	vi a = vi(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int l = -1;
	ll l_sum = 0;

	int r = n;
	ll r_sum = 0;

	ll max_sum = -1;
	while(l < r){
		if(l_sum == r_sum){
			if(l_sum > max_sum)
				max_sum = l_sum;

			l++;
			l_sum += a[l];

			r--;
			r_sum += a[r];
		}else if(l_sum < r_sum){
			l++;
			l_sum += a[l];
		}else{
			r--;
			r_sum += a[r];
		}
	}

	cout << max_sum;

	return 0;
}