/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

vll a;
vll taken;
ll n, c;

bool p(ll mid, ll start_index){
	if((a[mid] % c) == 0){
		if((a[mid] / c) >= a[start_index])
			return true;
		else
			return false;
	}else{
		if(((a[mid] / c) + 1) > a[start_index])
			return true;
		else
			return false;
	}
}

// bool p(ll mid, ll start_index){
// 	if(a[mid] >= (c * a[start_index]))
// 		return true;
// 	return false;
// }

ll skip_taken(ll i){
	while((i < n) && (taken[i] == 1))
		i++;
	return i;
}

ll find(ll start_index, ll k){

	ll lo = start_index + 1;
	ll hi = n - 1;
	ll mid;
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(p(mid, start_index))
			hi = mid;
		else
			lo = mid + 1;
	}

	if(!p(lo, start_index)){
		return 0;
	}

	lo = skip_taken(lo);
	if(lo >= n){
		return 0;
	}

	taken[lo] = 1;
	if(k == 1){
		return 1;
	}	
	return find(lo, k - 1);

}

void show_taken(){
	for(int i = 0; i < n; i++)
		cout << taken[i] << " ";
	cout << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	ll k;
	while(t--){
		
		cin >> n >> k >> c;

		a = vll(n);
		taken = vll(n, 0);
		for(ll i = 0; i < n; i++)
			cin >> a[i];

		sort(a.begin(), a.end());

		if(k == 1){
			cout << n << endl;
			continue;
		}

		if(k > n){
			cout << 0 << endl;
			continue;
		}

		ll ans = 0;
		ll start_index = 0;

		while(true){
			taken[start_index] = 1;
			if(find(start_index, k - 1)){
				//show_taken();
				ans++;
			}
			start_index = skip_taken(start_index);
			if(start_index >= n)
				break;
		}
		
		cout << ans << endl;
		
	}		

	return 0;
}