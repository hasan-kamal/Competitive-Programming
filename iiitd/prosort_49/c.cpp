#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

vvd a;
vd dp;

double maximum(double x, double y){
	return x>y?x:y;
}

double assign_jobs(int n, int mask, int num_jobs){
	//0th to (n-1)-th bit

	if(dp[mask]>=0)
		return dp[mask];

	if(n==1){
		
		//find the unset bit in mask
		for(int i=0; i<num_jobs; i++){
			if((mask&(1<<i))==0){
				dp[mask] = a[0][i];
				return dp[mask];
			}
		}

	}else{

		double max = INT_MIN;
		for(int i=0; i<num_jobs; i++){
			if((mask&(1<<i))==0){
				//i-th bit is not set
				int new_mask = (mask | (1<<i));
				max = maximum(max, a[n-1][i] + assign_jobs(n-1, new_mask, num_jobs));
			}
		}
		dp[mask] = max;
		return dp[mask];

	}
}

int main(){

	int n;
	cin>>n;

	dp = vd((1<<(n+1))-1, -1);

	a = vvd(n, vd(n));
	int temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>temp;
			a[i][j] = log(temp);
		}
	}

	int mask = 0;
	double log_p=assign_jobs(n, mask, n);
	log_p-=(n*log(100.0));
	double p = exp(log_p);
	printf("%.6lf", p*100.0);

	return 0;
}