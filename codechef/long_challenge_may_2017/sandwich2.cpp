#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll p(ll base, ll power, ll m){
	if(power==0)
		return 1;
	else if(power==1){
		return base%m;
	}else if(power%2==0){
		return (p(base, power/2, m)*p(base, power/2, m))%m;
	}else
		return (p(base, power-1, m)*p(base, 1, m))%m;
}

ll C(ll n, ll r, ll m){
	if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans = (ans%m * (n - r + i)%m)%m;
        ans = (ans%m * p(i, m-2, m))%m;
    }

    return ans%m;
}

int main(){

	ll t;
	ll n, k, m;
	cin>>t;

	while(t--){
		cin>>n>>k>>m;
		if(k>=n)
			cout<<"1 1"<<endl;
		else if(n%k==0){
			cout<<n/k<<" 1"<<endl;
		}else{

			ll groups;
			groups = n/k + 1;
			cout<<groups<<" "<<C(groups*(k+1)-n-1, groups-1, m)%m<<endl;
		
		}
	}

	return 0;
}