#include <iostream>
#include <string>
using namespace std;

int main(){

	string s;
	int t = 0;
	while(getline(cin, s)){
		if(s.compare("#") == 0)
			break;
		if(s.compare("HELLO") == 0){
			cout << "Case " << ++t << ": " << "ENGLISH" << endl;
		}else if(s.compare("HOLA") == 0){
			cout << "Case " << ++t << ": " << "SPANISH" << endl;
		}else if(s.compare("HALLO") == 0){
			cout << "Case " << ++t << ": " << "GERMAN" << endl;
		}else if(s.compare("BONJOUR") == 0){
			cout << "Case " << ++t << ": " << "FRENCH" << endl;
		}else if(s.compare("CIAO") == 0){
			cout << "Case " << ++t << ": " << "ITALIAN" << endl;
		}else if(s.compare("ZDRAVSTVUJTE") == 0){
			cout << "Case " << ++t << ": " << "RUSSIAN" << endl;
		}else{
			cout << "Case " << ++t << ": " << "UNKNOWN" << endl;
		}

	}

	return 0;
}