#include <iostream>
#include <cstdio>
using namespace std;

int main(){

	double d = 1.3;
	for(int i = 0; i < 10; i++){
		printf("%10.5f\n", d + i * 10);
	}

	return 0;
}