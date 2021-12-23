#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll mn(ll a, ll b){
	return a < b ? a : b;
}

ll n, k, a, b;
vll arr;

ll pow(ll a, ll e){
	ll ans = 1;
	for(int i = 1; i <= e; i++)
		ans = ans * a;
	return ans;
}

ll ppos(ll val){
	ll start = 0;
	ll end = k + 1;
	ll mid;
	while(start < end){
		mid = start + (end - start + 1) / 2;
		if(arr[mid] > val)
			end = mid - 1;
		else
			start = mid;
	}
	return start;
}

ll num_in(ll a, ll b){
	return ppos(b) - ppos(a - 1);
}


ll f(ll start, ll end){
	ll num = num_in(start, end);
	if(start == end){
		if(num == 0)
			return a;
		else
			return b * num * (end - start + 1);
	}

	ll here = a;
	if(num > 0){
		here = b * num * (end - start + 1);
	}else if(num == 0){
		return a;
	}

	ll left = f(start, start + (end - start - 1) / 2);
	ll right = f(start + (end - start + 1) / 2, end);

	// cout << start << " " << end << " " << mn(here, left + right) << endl;

	return mn(here, left + right);
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k >> a >> b;
	n = pow(2, n);
	
	arr = vll(k + 2);
	arr[k] = -1;
	arr[k + 1] = pow(2, 31);
	ll pos;
	for(int i = 0; i < k; i++){
		cin >> pos;
		arr[i] = pos;
	}
	sort(arr.begin(), arr.end());
	cout << f(1, n);

	return 0;
}