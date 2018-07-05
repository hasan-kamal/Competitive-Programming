/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#define V 10000000
using namespace std;

int main(){

	srand(time(NULL));

	int T, N;
	cin >> T >> N;

	cout << T << endl;
	while(T--){

		int c = rand() % N + 1;
		cout << N << " " << c << endl;
		while(c--){

			int ch = rand() % 2;
			int p, q, v;
			p = rand() % N + 1;
			q = rand() % N + 1;
			if(p > q){
				int temp  = p;
				p = q;
				q = temp;
			}
			if(ch == 0){
				v = rand() % V;
				cout << ch << " ";
				cout << p << " ";
				cout << q << " ";
				cout << v << endl;
			}else{
				cout << ch << " ";
				cout << p << " ";
				cout << q << " ";
			}

		}

	}

	return 0;
}