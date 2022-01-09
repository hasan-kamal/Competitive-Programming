#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	int a, b, c;
	int t = 0;
	while(n--){
		cin >> a >> b >> c;
		if(a <= 20 && b <= 20 && c <= 20)
			cout << "Case " << ++t << ": good" << endl;
		else
			cout << "Case " << ++t << ": bad" << endl;
	}

	return 0;
}