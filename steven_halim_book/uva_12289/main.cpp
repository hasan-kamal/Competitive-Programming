#include <iostream>
#include <string>
using namespace std;

int main(){

	int n;
	cin >> n;

	string s;
	while(n--){
		cin >> s;
		if(s.length() == 5){
			cout << 3 << endl;
			continue;
		}
		int mismatch = 0;
		mismatch += (s[0] != 'o' ? 1 : 0);
		mismatch += (s[1] != 'n' ? 1 : 0);
		mismatch += (s[2] != 'e' ? 1 : 0);
		if(mismatch <= 1)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}

	return 0;
}