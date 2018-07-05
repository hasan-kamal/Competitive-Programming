/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = 0, p = 0;
	for(char ch : s)
		if(ch == 'o')
			p++;
		else
			n++;

	if(p == 0)
		cout << "YES" << endl;
	else if(n % p == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}