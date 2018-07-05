/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

int main(){

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;

		int lower_power_two = 1;
		for(int i = 30; i >= 0; i--){
			if((n & (1 << i)) != 0){
				lower_power_two = (1 << i);
				break;
			}
		}

		cout << 1 + 2 * (n - lower_power_two) << endl;
	}

	return 0;
}