/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, a, b, n;
	cin >> t;

	while(t--){
		cin >> a >> b >> n;
		if(n % 2 == 0)
			cout << max(a, b) / min(a, b) << endl;
		else
			cout << max(a * 2, b) / min(a * 2, b) << endl;
	}

	return 0;
}