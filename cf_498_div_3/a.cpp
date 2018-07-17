#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < n; i++)
		if(a[i] % 2 == 0)
			a[i] = a[i] - 1;

	for(int x : a)
		cout << x << " ";

	return 0;
}