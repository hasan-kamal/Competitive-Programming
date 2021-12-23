/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int i = n - 1;
	int j = 0;
	while(j < i){
		i--;
		if(j >= i)
			break;
		j++;
	}

	// cout << i << endl;
	// int lo = ( n - 1 ) / 2;
	cout << a[i];

	return 0;
}