/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;

		vi a = vi(n + 1, 0);

		int q;
		cin >> q;

		int ch, l, r, val;
		while(q--){

			cin >> ch;

			if(ch == 0){
				cin >> l >> r >> val;
				for(int i = l; i <= r; i++)
					a[i] += val;
				continue;
			}

			cin >> l >> r;
			int sum = 0;
			for(int i = l; i <= r; i++)
				sum += a[i];
			cout << sum << endl;

		}

	}

	return 0;
}