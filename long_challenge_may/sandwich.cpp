#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

ll C(ll n, ll r, ll m){
	if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans = ans * (n - r + i);
        ans = ans/i;
    }

    return ans%m;
}

ll f(ll n, ll num_markers, ll k, ll m){
	ll ans = 0;
	if(num_markers<0)
		ans = 0;
	else if(num_markers==0){
		if(n+1<=k)
			ans = 1;
		else
			ans = 0;
	}else if(num_markers>n)
		ans = 0;
	else if(n<=k)
		ans = C(n, num_markers, m)%m;
	else{

		ans = 0;
		for(ll i=1; i<=k; i++)
			ans+=(f(n-i, num_markers-1, k, m)%m);

	}

	//cout<<"n,alpha,k: "<<n<<","<<num_markers<<","<<k<<": ";
	//cout<<ans<<endl;
	
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
		else{

			ll min;
			if(n%k==0)
				min = n/k;
			else
				min = n/k + 1;
			
			ll num_markers = min-1;

			cout<<min<<" "<<f(n-1, num_markers, k, m)%m<<endl;
		}
	}

	return 0;
}