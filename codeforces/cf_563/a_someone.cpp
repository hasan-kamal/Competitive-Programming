#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	int arr[2 * n], arro[2 * n], conta = 0, contb = 0;
	for(int i = 0; i < 2 * n; i++){
		cin >> arr[i];
		if(i < n) conta += arr[i];
		else contb += arr[i];
	}

	int contacopy = conta;
	int contbcopy = contb;

	for(int i = 0; i < 2 * n; i++) arro[i] = arr[i];

	for(int j = 0; j < n; j++){
		for(int i = n; i < 2 * n; i++){
			if(conta != contb){
				for(int k = 0; k < 2 * n; k++) cout << arro[k] << " ";
				cout << '\n';
				return 0;
			}
			for(int i = 0; i < 2 * n; i++) arro[i] = arr[i];
			conta = contacopy;
			contb = contbcopy;
			conta = conta - arro[j] + arro[i];
			contb = contb - arro[i] + arro[j];
			swap(arro[j], arro[i]);
		}
	}
	cout << "-1\n";

	return 0;
}