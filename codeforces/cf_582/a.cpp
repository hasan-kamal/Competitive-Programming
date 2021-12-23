#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	int temp, e = 0, o = 0;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp % 2 == 0)
			e++;
		else
			o++;
	}
	cout << min(e, o) << endl;

	return 0;
}