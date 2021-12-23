#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;

	string s;
	while(n--){
		cin >> s;
		if(s.compare("1") == 0 || s.compare("4") == 0 || s.compare("78") == 0)
			cout << "+" << endl;
		else if(s[s.length() - 2] == '3' && s[s.length() - 1] == '5')
			cout << "-" << endl;
		else if(s[0] == '9' && s[s.length() - 1] == '4')
			cout << "*" << endl;
		else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
			cout << "?" << endl;
	}

	return 0;
}