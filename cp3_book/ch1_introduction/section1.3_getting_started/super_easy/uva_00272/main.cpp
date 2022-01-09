#include <iostream>
#include <string>
using namespace std;

int main(){

	string s;
	int state = 1;
	while(getline(cin, s)){
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '\"'){
				state = 1 - state;
				string out = state == 0 ? "``" : "\'\'";
				cout << out;
			}else
				cout << s[i];
		}
		cout << endl;
	}

	return 0;
}