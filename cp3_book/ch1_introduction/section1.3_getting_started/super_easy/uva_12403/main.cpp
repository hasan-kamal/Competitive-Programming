#include <iostream>
#include <string>
using namespace std;

int main(){

	int t;
	cin >> t;

	string s;
	int sum = 0;
	while(t--){
		cin >> s;
		if(s.compare("donate") == 0){
			int k;
			cin >> k;
			sum += k;
		}else{
			cout << sum << endl;
		}

	}

	return 0;
}