/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;

int f(int n){
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else
		return n + f(n - 2);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << f(n);	
	
	return 0;
}