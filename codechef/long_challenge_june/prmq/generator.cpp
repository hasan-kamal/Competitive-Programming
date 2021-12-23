/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){

	int n, q, a;
	cin >> n >> q >> a;

	srand(time(NULL));
	
	cout << n << endl;
	for(int i = 0; i < n; i++)
		cout << rand() % a + 2 << endl;

	cout << q << endl;
	int l, r, x, y;
	for(int i = 0; i < q; i++){
		l = rand() % n + 1;
		
		if(l == n)
			r = n;
		else
			r = l + (rand() % (n - l));

		x = rand() % a + 1;
		y = rand() % a + 1;
		cout << l << " " << r << " " << x << " " << y << endl;
	}

	return 0;
}