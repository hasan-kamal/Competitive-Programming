#include <iostream>
#include <vector>
using namespace std;

int main(){

	long long int a[61][61];

	for(int i = 0; i < 61; i++){
		a[0][i] = 1;
		a[1][i] = 1;
	}

	for(int i = 2; i < 61; i++){
		a[i][0] = 1;
		for(int j = 1; j < 61; j++){
			a[i][j] = 1;
			for(int k = 1; k <= j; k++)
				 a[i][j] += i - k < 0 ? 1 : a[i - k][j];
		}
	}

	int n, m, t = 0;
	while(cin >> n >> m){
		if(n > 60)
			break;
		cout << "Case " << ++t << ": " << (n >= 0 ? a[n][m] : 1) << endl;
	}

	return 0;
}