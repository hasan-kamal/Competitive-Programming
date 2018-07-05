/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;
typedef vector<dii> vdii;

int maxval;

int f(int v, int lo, int hi){

	if(v > maxval)
		maxval = v;

	if(lo != hi){
		int mid = lo + (hi - lo) / 2;
		return f(2 * v, lo, mid) + f(2 * v + 1, mid + 1, hi) + 1;
	}
	
	return 1;

}

int main(){

	int n;
	cin >> n;

	vdii v = vdii();
	for(int i = 1; i <= n; i++){
		maxval = -1;
		double val = (double)f(1, 1, i);
		double first = ((double) maxval) / i;
		ii second = make_pair(maxval, i);
		v.push_back(make_pair(first, second));
	}

	sort(v.rbegin(), v.rend());

	for(int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second.first << " " << v[i].second.second << endl;

	return 0;
}