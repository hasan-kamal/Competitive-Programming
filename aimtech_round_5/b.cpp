#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n - 1; i++)
		cout << 8;
	cout << 9 << endl;

	for(int i = 0; i < n; i++)
		cout << 1;

	return 0;
}