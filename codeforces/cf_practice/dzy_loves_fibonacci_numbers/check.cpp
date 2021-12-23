/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

int main(){

	int n = 100;

	int i;
	for(int x = 1; x <= n; x++){
		i = x;
		i = x & -x;
		cout << i << endl;
	}

	return 0;
}