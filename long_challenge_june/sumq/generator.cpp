/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


int main(){

	int T, P, Q, R, MAX_VAL;
	cin >> T >> P >> Q >> R >> MAX_VAL;

	srand(time(NULL));
	int t = rand() % T + 1;
	cout << t << endl;
	while(t--){
		int p = rand() % P + 1;
		int q = rand() % Q + 1;
		int r = rand() % R + 1;
		cout << p << " " << q << " " << r << endl;
		
		for(int i = 0; i < p; i++)
			cout << rand() % MAX_VAL + 1 << " ";
		cout << endl;

		for(int i = 0; i < q; i++)
			cout << rand() % MAX_VAL + 1 << " ";
		cout << endl;

		for(int i = 0; i < r; i++)
			cout << rand() % MAX_VAL + 1 << " ";
		cout << endl;
	}

	return 0;
}
