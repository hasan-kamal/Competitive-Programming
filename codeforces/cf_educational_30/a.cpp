/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	int n, k, x;
	cin >> n >> k >> x;

	int sum = 0;
	int t;
	for(int i = 0; i < n - k; i++){
		cin >> t;
		sum += t;
	}

	sum += x * k;

	cout << sum;

	return 0;
}