/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximum(int a, int b){
	return a > b ? a : b;
}

int minimum(int a, int b){
	return a < b ? a : b;
}

int main(){

	int n, m;
	cin >> n >> m;

	const int max = 101;
	char a[max][max];

	int num_black_init = 0;
	int max_r = INT_MIN;
	int min_l = INT_MAX;
	int min_t = INT_MAX;
	int max_b = INT_MIN;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
			if(a[i][j] == 'B'){
				num_black_init++;
				if(j > max_r)
					max_r = j;
				if(j < min_l)
					min_l = j;
				if(i > max_b)
					max_b = i;
				if(i < min_t)
					min_t = i;
			}
		}
	}


	if(num_black_init == 0){
		cout << "1";
		return 0;
	}

	int length = maximum(max_r - min_l + 1, max_b - min_t + 1);

	// cout << min_l << endl;
	// cout << max_r << endl;
	// cout << min_t << endl;
	// cout << max_b << endl;
	// cout << length << endl;
	
	if(length <= minimum(n, m)){
		cout << length * length - num_black_init;
	}else
		cout << "-1";

	return 0;
}