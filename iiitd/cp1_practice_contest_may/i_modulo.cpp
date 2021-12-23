/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define M 1000000007

typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

ll n, q, f1, f2, a, b;
vll arr;
vll increment; //actual stuff
vvpll starting;
vvpll ending;
vll dp;

int main(){

	cin>>n>>q;
	cin>>f1>>f2;
	cin>>a>>b;

	arr = vll(n+1);
	for(ll i=1; i<=n; i++)
		cin>>arr[i];

	dp = vll(n+1);
	dp[1] = f1;
	dp[2] = f2;
	for(ll i=3; i<=n; i++){
		dp[i] = ( ((a*(dp[i-2]%M))%M) + ((b*(dp[i-1]%M))%M) )%M;
	}

	ll l, r;
	starting = vvpll(n+1, vpll());
	ending = vvpll(n+1, vpll());
	pll range;
	for(ll i=0; i<q; i++){
		cin>>range.first>>range.second;
		starting[range.first].push_back(range);
		ending[range.second].push_back(range);
	}

	ll s1, s2, s3;

	s1 = (((ll)starting[1].size())%M * (f1%M))%M;
	s2 = (((ll)starting[2].size())%M * (f1%M))%M;
	ll number_starting_one_greater_than_unity = 0;
	for(pll r : starting[1]){
		if(r.second>r.first){
			number_starting_one_greater_than_unity = (number_starting_one_greater_than_unity+1)%M;
		}
	}
	s2 = (s2 + (number_starting_one_greater_than_unity*(f2%M))%M )%M;

	increment = vll(n+1);
	increment[1] = s1;
	increment[2] = s2;
	
	for(int i=3; i<=n; i++){
		s3 = ((a*s1)%M + (b*s2)%M)%M;
		
		//t2
		for(pll r : ending[i-1]){
			if(r.second>r.first){
				s3 = (s3 + M - dp[r.second-r.first+2])%M;
			}
		}

		//t3
		for(pll r : ending[i-1]){
			if(r.second==r.first){
				s3 = (s3 + M - (b*f1)%M)%M;
			}
		}

		//t4
		for(pll r : ending[i-2]){
			s3 = (s3 + M - (a*dp[r.second-r.first+1])%M)%M;
		}

		//t5
		for(pll r : starting[i-1]){
			if(r.second>r.first){
				s3 = ( (s3 + M - (b*f1)%M)%M + f2)%M;
			}
		}

		//t6
		for(pll r : starting[i]){
			s3 = (s3 + f1)%M;
		}

		increment[i] = s3;
		s1 = s2;
		s2 = s3;
	}

	//show result[i] = increment[i] + arr[i]
	for(int i=1; i<=n; i++){
		cout<< ((arr[i]%M) + (increment[i]%M))%M <<" ";
	}

	return 0;
}