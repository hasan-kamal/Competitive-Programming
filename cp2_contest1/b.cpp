/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

vi a;
ll triples(int low, int high){
	if(high - low <= 1)
		return 0;

	int mid = low + (high - low) / 2;

	ll cross_1 = 0;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NUL);

	int n;
	cin >> n;

	a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	cout << triples(0, n - 1);

	return 0;
}