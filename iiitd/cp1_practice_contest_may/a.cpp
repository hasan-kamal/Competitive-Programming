/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

int n, m, max_group_size;
vi groups;

int ceil(int a, int b){
	return a%b==0?a/b:a/b+1;
}

bool p(int maximum_students_per_mic){
	int num_mics_needed = 0;
	for(int i=0; i<n; i++)
		num_mics_needed+=(ceil(groups[i], maximum_students_per_mic));

	if(num_mics_needed<=m)
		return true;
	else
		return false;
}

int maximum_students_to_any_mic(){
	int lo = 1;
	int hi = max_group_size;
	int mid;

	while(lo<hi){
		mid = lo + (hi-lo)/2;
		if(p(mid))
			hi = mid;
		else
			lo = mid+1;
	}

	return lo;
}

int main(){

	cin>>n>>m;

	groups = vi(n);
	max_group_size = INT_MIN;
	for(int i=0; i<n; i++){
		cin>>groups[i];
		if(groups[i]>max_group_size)
			max_group_size = groups[i];
	}

	cout<<maximum_students_to_any_mic();

	return 0;
}