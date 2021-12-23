/*

@author Hasan Kamal
DP + bitmasking bare bones
function uses only one state as dp parameter
submit under C++11 on FCP, doesn't work for C++ for some reason gives RTE

*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <cfloat>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;

vvd a;
vd dp;
int n;

double maximum(double x, double y){
	return x>y?x:y;
}

//we'll assign jobs to bonds in the order
//bond(0), bond(1), ..., bond(n-1)
//simplifies as then our recursive function requires only one dp state as parameter - mask
//and we lose nothing by doing this as it does not matter in which order we assing jobs
double assign_jobs(int mask){
	
	if(dp[mask]>=0.0)
		return dp[mask];

	vi unset_bits = vi();
	int num_unset_bits = 0;
	for(int i = 0; i <= n-1; i++){
		if( (mask&(1<<i)) == 0){
			unset_bits.push_back(i);
			num_unset_bits++;
		}
	}

	if(num_unset_bits==1){
		dp[mask] = a[n-1][unset_bits[0]]; //only one job left unassigned, must be assigned to bond(n-1) because of the order in which we are assigning
	}else{
		//have to assign job to bond(n-num_unset_bits) since we're assigning in the order bond(0), bond(1), ...
		//try all possible jobs that are not yet assigned
		double max = DBL_MIN;
		for(int x = 0; x<num_unset_bits; x++){
			int i = unset_bits[x];
			mask = mask | (1<<i); //assign job i to bond(n-num_unset_bits)
			max = maximum(max, a[n-num_unset_bits][i] + assign_jobs(mask));
			mask = mask & ~(1<<i); //deassign job i to bond(n-num_unset_bits)
		}
		dp[mask] = max;
	}

	return dp[mask];
}

int main(){

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
	double log_p=assign_jobs(mask);
	log_p-=(n*log(100.0));
	double p = exp(log_p);
	printf("%.6lf", p*100.0);

	return 0;
}