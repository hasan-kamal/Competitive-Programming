/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;

	int n1 = a.length();
	int n2 = b.length();

	int last_picked = 0;
	while(last_picked + 1< n1 && a[last_picked + 1] < b[0])
		last_picked++;
	
	string c = a.substr(0, last_picked + 1) + b[0];
	cout << c;
	
	return 0;
}