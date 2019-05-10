/*
	@author Hasan Kamal
	Forming quiz teams problem, UVa - 10911
	Solution using bitmasking and DP
*/

#include <iostream>
#include <vector>
#include <set>
#include <cfloat>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<string> vs;
typedef set<iii> siii;
typedef vector<double> vd;
vd dp;

double dist(iii p1, iii p2){
	return sqrt((p1.second.first-p2.second.first)*(p1.second.first-p2.second.first) + (p1.second.second-p2.second.second)*(p1.second.second-p2.second.second));
}

double minimum(double x, double y){
	return x<y?x:y;
}

double min_dist(siii &points){

	int mask = 0;
	for(siii::iterator it = points.begin(); it!=points.end(); it++){
		//set (*it).first-th bit of mask
		int b = (*it).first;
		mask |= (1<<b);
	}

	if(dp[mask]>=0){
		return dp[mask];
	}

	iii p1, p2;
	siii::iterator it=points.begin();
	p1 = *it;
	it++;
	p2 = *it;

	if(points.size()==2){
		dp[mask] = dist(p1, p2);
	}else{
			
		double min_ans = DBL_MAX;
		siii::iterator it = points.begin();
		it++;
		for(; it!=points.end(); it++){
			siii smaller_set = siii(points);
			smaller_set.erase(*it);
			smaller_set.erase(p1);
			min_ans = minimum(min_ans, dist(p1, *it)+min_dist(smaller_set));
		}

		dp[mask] = min_ans;
	}

	return dp[mask];
}

int main(){

	int n;
	cin>>n;
	int t=0;
	while(n){

		siii points = siii();
		int dp_size = (1<<(2*n));
		dp = vd(dp_size, -1);

		string name;
		int x, y;
		for(int i=0; i<2*n; i++){
			cin>>name>>x>>y;
			iii e;
			e.first = i;
			e.second.first = x;
			e.second.second = y;
			points.insert(e);
		}

		printf("Case %d: %.2lf\n", t+1, min_dist(points));

		cin>>n;
		t++;
	}

	return 0;
}