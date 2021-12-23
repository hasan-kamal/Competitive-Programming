/*

@author Hasan Kamal

*/
#include <iostream>
#include <vector>
#include <cfloat>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

bool p(double t, int n, vi &x, vi &v){
	double max_l = -DBL_MAX;
	double min_r = DBL_MAX;

	double l, r;
	for(int i=0; i<n; i++){
		l = x[i] - v[i]*t;
		r = x[i] + v[i]*t;

		if(l>max_l)
			max_l = l;

		if(r<min_r)
			min_r = r;
	}

	if(max_l<=min_r)
		return true;
	else
		return false;
}

int main(){

	int n;
	cin>>n;

	vi x(n);
	vi v(n);

	for(int i=0; i<n; i++)
		cin>>x[i];

	for(int i=0; i<n; i++)
		cin>>v[i];

	double lo = 0.0;
	double hi = 1.0e10; 
	double mid;	
	while((hi-lo)>1.0e-7){

		if(mid==(lo + (hi-lo)/2.0))
			break;

		mid = lo + (hi-lo)/2.0;

		if(p(mid, n, x, v))
			hi = mid;
		else
			lo = mid;

	}
	mid = lo + (hi-lo)/2.0;
	printf("%.12lf", mid);;

	return 0;
}