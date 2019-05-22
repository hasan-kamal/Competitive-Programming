#include <iostream>
using namespace std;

int main(){

	int t;
	cin >> t;

	int a, b;
	while(t--){
		cin >> a >> b;
		cout << ( a - b > 0 ? '>' : (a - b == 0 ? '=' : '<') ) << endl;
	}

	return 0;
}