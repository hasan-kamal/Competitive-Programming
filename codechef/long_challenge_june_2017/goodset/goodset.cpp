/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

	int t;
	cin >> t;

	int n;
	while(t--){

		cin >> n;

		if(n == 1){
			cout << "1" << endl;
			continue;
		}

		for(int i = n - 1; i <= 2*n - 2; i++)
			cout << i << " ";
		cout << endl;

	}

	return 0;
}