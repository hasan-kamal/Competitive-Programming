/*

@author hasankamal

*/

#include <iostream>
#include <climits>
using namespace std;

int f(int v){
	int sum = 0;
	while(v){
		sum += (v % 10);
		v /= 10;
	}
	return sum;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int best = INT_MAX;
	for(int a = 1; n - a >= 1; a++){
		int b = n - a;

		int s = f(a) + f(b);
		if(s < best)
			best = s;
	}

	cout << best;
	
	return 0;
}