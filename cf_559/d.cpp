#include <iostream>
using namespace std;

int main(){

	int n, k;
	cin >> n >> k;

	int a = (n - k) / 2;
	int length = 0;
	while(length <= n - (a + 1)){
		for(int i = 0; i < a; i++)
			cout << "0";
		cout << "1";
		length += (a + 1);
	}
	while(length < n){
		cout << "0";
		length++;
	}

	return 0;
}