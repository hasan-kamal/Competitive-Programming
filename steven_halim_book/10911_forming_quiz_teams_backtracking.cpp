/*
	Uva 10911 - solution using backtracking and clever pruning
	@author Hasan Kamal
*/

#include <iostream>
#include <cfloat>
#include <cmath>
using namespace std;

#include <vector>
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vii points;
vi selected;
int n;
double min_so_far;

double dist(int i, int j){
	ii p1 = points[i];
	ii p2 = points[j];
	return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

double minimum(double x, double y){
	return x<y?x:y;
}

double pair_min(int index, int num_unselected, double sum_so_far){

	if(num_unselected==0){
		if(sum_so_far<min_so_far)
			min_so_far = sum_so_far;
		return 0.0;
	}

	if(sum_so_far>min_so_far)
		return 0.0;

	while(selected[index]==1)
		index++; //find first unselected one, needed because index-th might already be selected

	double ans, min_ans=DBL_MAX;
	for(int j=index+1; j<2*n; j++){
		if(selected[index]==0 && selected[j]==0){
			selected[index] = 1;
			selected[j] = 1;
			
			ans = dist(index, j) + pair_min(index+1, num_unselected-2, sum_so_far+dist(index, j));
			if(ans<min_ans)
				min_ans = ans;

			selected[index] = 0;
			selected[j] = 0;
		}
	}

	return min_ans;
}

int main(){

	cin>>n;

	int t=0;
	while(n){
		points = vii(2*n);
		string name;
		for(int i=0; i<2*n; i++){
			cin>>name>>points[i].first>>points[i].second;
		}

		selected = vi(2*n, 0);
		min_so_far = DBL_MAX;
		double ans = pair_min(0, 2*n, 0.0);
		
		printf("Case %d: %.2lf\n", t+1, ans);
		cin>>n;
		t++;
	}
	
	return 0;
}