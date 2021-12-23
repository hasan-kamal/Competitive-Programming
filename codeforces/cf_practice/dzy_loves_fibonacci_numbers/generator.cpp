/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<int> vi;

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

int main(){

	srand(time(NULL));

	int t;
	cin >> t;

	int n;
	cin >> n;

	int q;
	cin >> q;

	cout << t << endl;

	while(t--){

		cout << n << " " << q << endl;

		int ch, l, r, val;
		for(int x = 0; x < q; x++){

			ch = rand() % 2;
			cout << ch << endl;

			l = rand() % n + 1;
			r = rand() % n + 1;
			if(l > r)
				swap(l, r);
			
			if(ch == 0){
				//update
				val = rand() % n + 1;
				cout << l << " " << r << " " << val << endl;
				continue;
			}

			//query
			cout << l << " " << r << endl;

		}

	}

	return 0;
}