/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef vector<set<ll> > vsll;

vll h;
ll sum;
vll prob;
vll prob_before;
vll running_sums;

ll cost(ll peak_index, ll end_index){
	ll n = end_index - peak_index;
	return running_sums[end_index] - (n+1)*(n+1);
}

ll minimum(ll x, ll y){
	return x<y?x:y;
}

ll maximum(ll x, ll y){
	return x>y?x:y;
}

int main(){

	ll t, n;
	cin>>t;

	while(t--){
		
		cin>>n;
		h = vll(n);
		prob = vll(n, -1);
		prob_before = vll(n, n+1);
		running_sums = vll(n);
		sum = 0;

		for(ll i=0; i<n; i++){
			cin>>h[i];
			sum+=h[i];

			if(i+h[i]<n){
				prob[i+h[i]] = maximum(prob[i+h[i]], i);
			}

			if(i-h[i]>=0){
				prob_before[i-h[i]] = minimum(prob_before[i-h[i]], i);
			}

			if(i==0)
				running_sums[i] = h[i];
			else
				running_sums[i] = running_sums[i-1] + h[i];
		}

		ll largest_problematic_index;
		for(ll i=0; i<n; i++){
			if(i%2==0)
				largest_problematic_index = i/2-1;
			else
				largest_problematic_index = i/2;
			prob[i] = maximum(prob[i], largest_problematic_index);
		}

		// for(ll i=0; i<n; i++){
		// 	cout<<"i:"<<i<<" prop_before:"<<prob_before[i]<<endl;
		// }
		
		for(ll i=n-2; i>=0; i--){
			prob_before[i] = minimum(prob_before[i], prob_before[i+1]);
		}

		// for(ll i=0; i<n; i++){
		// 	cout<<"i:"<<i<<" prop_before:"<<prob_before[i]<<endl;
		// }

		for(ll i=1; i<n; i++){
			prob[i] = maximum(prob[i], prob[i-1]);
			ll x = i - prob[i]-1;
			if(prob_before[prob[i]+1-x]<=prob[i]+1){
				prob[i]++;
			}
		}

		ll ans = h[0] - 1;
		for(ll i=1; i<n; i++){

			
			ll cost_ending_at_i = LONG_MAX;
			if(prob[i]+1<i)
				cost_ending_at_i = cost(prob[i]+1, i);
			
			ans = minimum(ans + h[i], cost_ending_at_i);
			
			//cout<<"::i="<<i<<" max_prob_ind="<<prob[i]<<" ans="<<ans<<endl;
		}

		cout<<ans<<endl;

	}

	return 0;
}