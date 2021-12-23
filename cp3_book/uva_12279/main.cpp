#include <iostream>
using namespace std;

int main(){

	int n;
	int t = 0;
	while(cin >> n){
		if(!n) break;
		int z = 0, temp;
		for(int i = 0; i < n; i++){
			cin >> temp;
			if(temp == 0) z++;
		}
		cout << "Case " << ++t << ": " << n - z - z << endl;
	}

	return 0;
}