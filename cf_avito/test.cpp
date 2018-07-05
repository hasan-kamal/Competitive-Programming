/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a;

	int n;
	cin >> n;
	while(n--){
		int val;
		cin >> val;
		a = a & val;
	}
	cout << a;

	return 0;
}