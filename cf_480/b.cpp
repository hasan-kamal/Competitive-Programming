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

	int n, k;
	cin >> n >> k;

	if(k % 2 == 0){
		cout << "YES" << endl;
		
		for(int i = 0; i < n; i++)
			cout << ".";
		cout << endl;

		cout << ".";
		for(int i = 0; i < k / 2; i++)
			cout <<  "#";
		for(int i = k / 2 + 1; i < n; i++)
			cout << ".";
		cout << endl;

		cout << ".";
		for(int i = 0; i < k / 2; i++)
			cout <<  "#";
		for(int i = k / 2 + 1; i < n; i++)
			cout << ".";
		cout << endl;

		for(int i = 0; i < n; i++)
			cout << ".";
	}else if(k == 1){
		cout << "YES" << endl;


		for(int i = 0; i < n; i++)
			cout << ".";
		cout << endl;

		for(int i = 0; i < (n - 1) / 2; i++)
			cout <<  ".";
		cout << "#";
		for(int i = 0; i < (n - 1) / 2; i++)
			cout <<  ".";
		cout << endl;

		for(int i = 0; i < n; i++)
			cout << ".";
		cout << endl;

		for(int i = 0; i < n; i++)
			cout << ".";
	}else if(k == 3){
		cout << "YES" << endl;


		for(int i = 0; i < n; i++)
			cout << ".";
		cout << endl;

		for(int i = 0; i < (n - 3) / 2; i++)
			cout <<  ".";
		cout << "###";
		for(int i = (n - 3)/ 2 + 3; i < n; i++)
			cout << ".";
		cout << endl;

		for(int i = 0; i < n; i++)
			cout <<  ".";
		cout << endl;

		for(int i = 0; i < n; i++)
			cout <<  ".";

	}else{
		cout << "YES" << endl;


		for(int i = 0; i < n; i++)
			cout << ".";
		cout << endl;

		cout << ".";
		for(int i = 0; i < (k - 3) / 2; i++)
			cout <<  "#";
		cout << "##";
		for(int i = (k - 3)/ 2 + 1 + 2; i < n; i++)
			cout << ".";
		cout << endl;

		cout << ".";
		for(int i = 0; i < (k - 3)/ 2; i++)
			cout <<  "#";
		cout << ".#";
		for(int i = (k-3) / 2 + 1 + 2; i < n; i++)
			cout << ".";
		cout << endl;

		for(int i = 0; i < n; i++)
			cout << ".";
	}

	return 0;
}