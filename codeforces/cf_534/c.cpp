#include <iostream>
#include <vector>
#include <string>
#define S 100
#define T 200
#define Z 300
#define J 400
using namespace std;

typedef vector<int> vi;

void f(string &s, int length, int index, int state){

	if(index >= length)
		return;
	if(index == length - 1){
		// last move
		if(s[index] == '0'){
			cout << "4 1" << endl;
		}else{
			cout << "1 4" << endl;
		}
		return;
	}

	string l = s.substr(index, 2);

	if(state == S){
		if(l.compare("00") == 0){
			cout << "1 1" << endl;
			cout << "1 3" << endl;
			f(s, length, index + 2, S);
		}else if(l.compare("11") == 0){
			cout << "1 1" << endl;
			cout << "3 1" << endl;
			f(s, length, index + 2, S);
		}else if(l.compare("01") == 0){
			cout << "1 1" << endl;
			cout << "2 1" << endl;
			f(s, length, index + 2, T);
		}else if(l.compare("10") == 0){
			cout << "2 1" << endl;
			cout << "1 1" << endl;
			f(s, length, index + 2, T);
		}
	}else if(state == T){
		if(l.compare("00") == 0){
			cout << "4 3" << endl;
			cout << "4 1" << endl;
			f(s, length, index + 2, Z);
		}else if(l.compare("11") == 0){
			cout << "1 4" << endl;
			cout << "3 4" << endl;
			f(s, length, index + 2, T);
		}else if(l.compare("01") == 0){
			cout << "4 1" << endl;
			cout << "2 2" << endl;
			f(s, length, index + 2, S);
		}else if(l.compare("10") == 0){
			cout << "2 2" << endl;
			cout << "4 1" << endl;
			f(s, length, index + 2, S);
		}
	}else if(state == Z){
		if(l.compare("00") == 0){
			cout << "4 3" << endl;
			cout << "4 1" << endl;
			f(s, length, index + 2, Z);
		}else if(l.compare("11") == 0){
			cout << "1 4" << endl;
			cout << "3 4" << endl;
			f(s, length, index + 2, Z);
		}else if(l.compare("01") == 0){
			cout << "1 3" << endl;
			cout << "1 1" << endl;
			f(s, length, index + 2, J);
		}else if(l.compare("10") == 0){
			cout << "1 1" << endl;
			cout << "1 3" << endl;
			f(s, length, index + 2, J);
		}
	}else{
		if(l.compare("00") == 0){
			cout << "4 3" << endl;
			cout << "4 1" << endl;
			f(s, length, index + 2, J);
		}else if(l.compare("11") == 0){
			cout << "1 4" << endl;
			cout << "3 4" << endl;
			f(s, length, index + 2, J);
		}else if(l.compare("01") == 0){
			cout << "1 1" << endl;
			cout << "3 1" << endl;
			f(s, length, index + 2, Z);
		}else if(l.compare("10") == 0){
			cout << "3 1" << endl;
			cout << "1 1" << endl;
			f(s, length, index + 2, Z);
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] == '0')
			s[i] = '1';
		else
			s[i] = '0';
	}

	f(s, s.length(), 0, S);

	return 0;
}