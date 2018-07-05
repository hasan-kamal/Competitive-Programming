/*

@author Hasan Kamal
Solution to UVa-10911 using DP and bitmasking 
Bare-bones approach showing bitmasking usage, removed all obscure things
so that the actual usage of DP + bitmasking is apparent

*/

#include <iostream>
#include <vector>
#include <cfloat>
#include <cmath>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii points;
double dist(int i, int j){
	return sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second));
}

double minimum(double x, double y){
	return x<y?x:y;
}

vector<double> dp;
int n;
double get_minimal_pairing_dist(int mask){
	if(dp[mask]>0.0)
		return dp[mask];

	vector<int> unset_bits; //unset bits determine the set of points for which we would now have to compute the optimal minimum pairing sum
	for(int i = 0; i <= 2*n-1; i++)
		if( ((1<<i)&mask) ==0)
			unset_bits.push_back(i);

	int num_unset_bits = unset_bits.size();
	if(num_unset_bits == 2){
		
		//only two points remain, only one possible pairing
		dp[mask] = dist(unset_bits[0], unset_bits[1]);
	
	}else{
		
		//more than 2 unpaired points remain, try all possible pairings of first unpaired point with all other unpaired points and return the minimum you get
		int k = unset_bits[0]; //first unpaired point
		mask = mask | (1<<k); //mark it paired
		double min = DBL_MAX;
		for(int i=1; i<num_unset_bits; i++){ //try with all other unpaired points
			mask = mask | (1<<unset_bits[i]); //mark the chosen one paired
			min = minimum(min, dist(k, unset_bits[i]) + get_minimal_pairing_dist(mask)); //recurse
			mask = mask & ~(1<<unset_bits[i]); //unmark the chosen one
		}
		mask = mask & ~(1<<k); //unmark the first-originally-unpaired one
		dp[mask] = min; //store the result for this set

	}

	return dp[mask];
}

int main(){

	cin>>n;

	string name;
	int t = 0;
	while(n){

		points = vii(2*n);

		for(int i = 0; i < 2*n; i++){
			cin>>name;
			cin>>points[i].first>>points[i].second;
		}

		int mask = 0; //all zeroes denote that none points have been paired yet
		dp = vector<double>((1<<(2*n))-1, -1.0);
		printf("Case %d: %.2lf\n", ++t, get_minimal_pairing_dist(mask));

		cin>>n;
	}

	return 0;
}