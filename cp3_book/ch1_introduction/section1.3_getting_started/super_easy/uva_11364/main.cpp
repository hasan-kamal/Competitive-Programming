#include <iostream>
using namespace std;

int main(){

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		int min = 10000;
		int max = -1;
		int temp;
		for(int i = 0; i < n; i++){
			cin >> temp;
			if(temp < min) min = temp;
			if(temp > max) max = temp;
		}
		cout << 2 * (max - min) << endl;
	}

	return 0;
}