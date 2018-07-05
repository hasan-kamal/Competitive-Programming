/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

	int n;
	cin >> n;

	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			cout << "not prime" << endl;
			return 0;
		}
	}

	cout << "prime" << endl;

	return 0;
}