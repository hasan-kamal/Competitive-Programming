/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

iii mp(int x1, int x2, int x3){
	return make_pair(x1, make_pair(x2, x3));
}

iii extended_euclid(int a, int b){
	if(b == 0)
		return mp(a, 1, 0);
	else{
		iii temp = extended_euclid(b, a%b);
		return mp(temp.first, temp.second.second, temp.second.first - temp.second.second * (a / b));
	}
}

int main(){

	int a, b;
	cin >> a >> b;

	iii ans = extended_euclid(a, b);
	cout << "gcd=" << ans.first << endl;
	cout << "gcd=xa + yb" << endl;
	cout << "x=" << ans.second.first << endl;
	cout << "y=" << ans.second.second << endl;

	return 0;
}