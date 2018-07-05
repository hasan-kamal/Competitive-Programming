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

	int n;
	cin >> n;

	int a[100001];
	for(int i = 0; i < 100001; i++)
		a[i] = 0;

	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		a[temp]++;
	}

	bool all_even = true;
	for(int i = 1; i <= 100000; i++){
		if(a[i] % 2 != 0){
			all_even = false;
			break;
		}
	}

	if(all_even)
		cout << "Agasa";
	else
		cout << "Conan";

	return 0;
}