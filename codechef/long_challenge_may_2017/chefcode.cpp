#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long int ll;
vector<ll> arr;
vector<double> a_logs;
double l_k;
ll n;

ll calc_subsequences(ll index, double old_sum){
	
	if(index==n-1){
		ll ans = 0;

		if(old_sum+a_logs[index]<=l_k){
			//take n-1th element
			ans++;
		}

		if(old_sum<=l_k){
			//don't take last element
			ans++;
		}

		return ans;
	}

	if(old_sum>l_k){
		//printf("opt\n");
		return 0;
	}

	
	ll ans = 0;

	//taking index-th element
	ans+=calc_subsequences(index+1, old_sum+a_logs[index]);

	//not taking index-th element
	ans+=calc_subsequences(index+1, old_sum);

	return ans;
}

int main(){

	ll k;
	scanf("%lld %lld", &n, &k);

	ll temp;
	arr = vector<ll>();
	for(ll i=0; i<n; i++){
		scanf("%lld", &temp);
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	a_logs = vector<double>();
	for(ll i=0; i<n; i++){
		a_logs.push_back(log(arr[i]));
		//a_logs.push_back(arr[i]);
		//printf("%lf ", a_logs[i]);
	}

	l_k = log(k);
	
	ll ans = 0;
	ans = calc_subsequences(0, 0.0);
	printf("%lld", ans-1);

	return 0;
}