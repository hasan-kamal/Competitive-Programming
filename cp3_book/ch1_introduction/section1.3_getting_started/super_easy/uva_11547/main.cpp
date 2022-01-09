#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		cout << (abs((n * 63 + 7492) * 5 - 498) % 100) / 10 << endl;
	}

	return 0;
}