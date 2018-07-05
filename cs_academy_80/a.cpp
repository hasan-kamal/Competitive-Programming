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

	vi a(16);
	for(int i = 0; i < 16; i++){
		cin >> a[i];
	}

	int not_possible = 0;
	for(int i = 0; i < 16; i++){
		if(a[i] + 300 < a[3]){
			not_possible++;
			continue;
		}else if(a[i] + 300 == a[3]){
			not_possible++;
			continue;
		}
	}

	cout << 16 - not_possible;

	return 0;
}