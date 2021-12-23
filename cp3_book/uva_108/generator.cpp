#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

	int N = 30;
	cout << N << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++)
			cout << (rand() % 255) - 127 << " ";
		cout << endl;
	}

	return 0;
}