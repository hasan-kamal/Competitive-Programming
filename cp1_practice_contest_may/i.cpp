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

	/**
		MODULO STILL LEFT
	**/	

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
		dp[i] = a*dp[i-2] + b*dp[i-1];
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

	s1 = starting[1].size()*f1;
	s2 = starting[2].size()*f1;
	ll number_starting_one_greater_than_unity = 0;
	for(pll r : starting[1]){
		if(r.second>r.first)
			number_starting_one_greater_than_unity++;
	}
	s2 = s2 + number_starting_one_greater_than_unity*f2;

	increment = vll(n+1);
	increment[1] = s1;
	increment[2] = s2;
	
	for(int i=3; i<=n; i++){
		s3 = a*s1 + b*s2;
		
		//t2
		for(pll r : ending[i-1]){
			if(r.second>r.first){
				s3 = s3 - dp[r.second-r.first+2];
			}
		}

		//t3
		for(pll r : ending[i-1]){
			if(r.second==r.first){
				s3 = s3 - b*f1;
			}
		}

		//t4
		for(pll r : ending[i-2]){
			s3 = s3 - a*dp[r.second-r.first+1];
		}

		//t5
		for(pll r : starting[i-1]){
			if(r.second>r.first){
				s3 = s3 - b*f1 + f2;
			}
		}

		//t6
		for(pll r : starting[i]){
			s3 = s3 + f1;
		}

		increment[i] = s3;
		s1 = s2;
		s2 = s3;
	}

	//show result[i] = increment[i] + arr[i]
	for(int i=1; i<=n; i++){
		cout<<arr[i]+increment[i]<<" ";
	}

	//what about the case when n==1??

	return 0;
}