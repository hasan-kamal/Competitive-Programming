#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define N 300005
#define up 0
#define down 1

ll maximum(ll a, ll b){
	return a > b ? a : b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;

	vll a = vll(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vll b = vll(n);
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	vll total_beyond = vll(n, 0);
	total_beyond[n - 1] = a[n - 1] + b[n - 1];
	for(int i = n - 2; i >= 0; i--){
		total_beyond[i] = total_beyond[i + 1] + a[i] + b[i];
	}

	vll straight_up = vll(n, 0);
	straight_up[n - 1] = b[n - 1];
	for(int i = n - 2; i >= 0; i--){
		straight_up[i] = straight_up[i + 1] + total_beyond[i] - a[i] - b[i] + (2 * (n - i) - 1) * b[i];
	}

	vll straight_down = vll(n, 0);
	straight_down[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i--){
		straight_down[i] = straight_down[i + 1] + total_beyond[i] - b[i] - a[i] + (2 * (n - i) - 1) * a[i];
	}

	vll wiggle = vll(n, 0);
	wiggle[0] = 0;
	ll counter = 2;
	for(int i = 1; i < n; i++){
		if((i + 1) % 2 == 0){
			wiggle[i] = wiggle[i - 1] + (counter - 2) * a[i - 1] + (counter - 1) * b[i - 1];
		}else{
			wiggle[i] = wiggle[i - 1] + (counter - 2) * b[i - 1] + (counter - 1) * a[i - 1];
		}
		counter += 2;
	}

	// for(int i = 0; i < n; i++){
	// 	cout << straight_up[i] << " " << straight_down[i] << " " << wiggle[i] << endl;
	// }

	ll ans = -1;
	for(int i = 0; i < n; i++){
		if(i % 2 == 0)
			ans = maximum(ans, wiggle[i] + straight_up[i] + total_beyond[i] * (2 * i));
		else
			ans = maximum(ans, wiggle[i] + straight_down[i] + total_beyond[i] * (2 * i));
	}

	cout << ans;

	return 0;
}