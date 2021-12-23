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

	int n;
	cin >> n;

	if(n % 4 == 0){
		cout << 0 << endl;
		cout << n / 2 << " ";
		// for(int i = 1; i + 3 <= n; i += 4)
		// 	cout << i << " " << i + 3 << " ";
		for(int i = n; i - 3 >= 1; i -= 4)
			cout << i << " " << i - 3 << " ";
	}else if(n % 4 == 1){
		cout << 1 << endl;
		cout << (n - 1) / 2 << " ";
		for(int i = n; i - 3 >= 1; i -= 4)
			cout << i << " " << i - 3 << " ";
	}else if(n % 4 == 2){
		cout << 1 << endl;
		cout << n / 2 << " ";
		for(int i = n; i - 3 >= 1; i -= 4)
			cout << i << " " << i - 3 << " ";
		cout << 2 << " ";
	}else{
		cout << 0 << endl;
		cout << (n - 3) / 2 + 1 << " ";
		for(int i = n; i - 3 >= 1; i -= 4)
			cout << i << " " << i - 3 << " ";
		cout << 3 << " ";
	}

	return 0;
}