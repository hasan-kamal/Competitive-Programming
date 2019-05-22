#include <iostream>
using namespace std;

int ceil_div(int a, int b){
	if(a % b == 0)
		return a / b;
	return a / b + 1;
}

int main(){

	int t;
	cin >> t;

	int a, b;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << ceil_div(n - 2, 3) * ceil_div(m - 2, 3) << endl;
	}

	return 0;
}