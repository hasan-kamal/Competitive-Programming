#include <iostream>
#include <string>
using namespace std;

int main(){

	string s;
	int t = 0;
	while(getline(cin, s)){
		if(s.compare("*") == 0)
			continue;
		if(s[0] == 'H'){
			cout << "Case " << ++t << ": Hajj-e-Akbar" << endl;
		}else{
			cout << "Case " << ++t << ": Hajj-e-Asghar" << endl;
		}
	}

	return 0;
}