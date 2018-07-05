/*

@author Hasan Kamal

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define M 1000000009

typedef vector<int> vi;

int main(){

	srand(time(NULL));

	int n;
	cin >> n;

	int q;
	cin >> q;

	cout << n << endl;
	for(int i = 0; i < n; i++){
		cout << rand() % M + 1 << " ";
	}
	cout << endl;

	cout << q << endl;

	int i, j, k;
	while(q--){
		i = rand() % n + 1;
		j = rand() % n + 1;
		if(i > j){
			int temp = i;
			i = j;
			j = temp;
		}
		k = rand() % M + 1;
		cout << i << " " << j << " " << k << endl;
	}

	return 0;
}