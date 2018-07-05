/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, l, r;

	cin>>n;

	int earliest_r_chess=INT_MAX;
	int latest_l_chess=-1;
	int earliest_r_p=INT_MAX;
	int latest_l_p=-1;

	for(int i=0; i<n; i++){
		cin>>l>>r;
		if(r<earliest_r_chess)
			earliest_r_chess = r;
		if(l>latest_l_chess)
			latest_l_chess = l;
	}

	cin>>m;
	for(int i=0; i<m; i++){
		cin>>l>>r;
		if(r<earliest_r_p)
			earliest_r_p = r;
		if(l>latest_l_p)
			latest_l_p = l;
	}

	int a1 = latest_l_p - earliest_r_chess;
	int a2 = latest_l_chess - earliest_r_p; 
	if(a1<0 && a2<0){
		cout<<0;
	}else{
		cout<<max(a1, a2);
	}


	return 0;
}