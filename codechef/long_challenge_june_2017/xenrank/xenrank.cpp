/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){

	ll t;
	cin >> t;

	ll u, v;
	while(t--){
		cin >> u >> v;
		cout << ((u + v) * (u + v + 1) / 2) + 1 + u << endl;
	}

	return 0;
}