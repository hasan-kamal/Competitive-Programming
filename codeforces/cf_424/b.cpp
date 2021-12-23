/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<char, char> mcc;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string l1, l2;
	cin >> l1;
	cin >> l2;

	mcc m = mcc();
	for(int i = 0; i < 26; i++){
		m[l1[i]] = l2[i];
	}

	string s;
	cin >> s;
	for(char ch : s){
		if(ch >= '0' && ch <= '9')
			cout << ch;
		else{

			char tch = ch;
			if(tch >= 'A' && tch <= 'Z'){
				tch = 'a' + (tch - 'A');
			}

			char d = m[tch];
			if(ch >= 'A' && ch <= 'Z' && d >= 'a' && d <= 'z')
				d = 'A' + (d - 'a');
			else if(ch >= 'a' && ch <= 'z' && d >= 'A' && d <= 'Z')
				d = 'a' + (d - 'A');
			cout << d;
		}
	}


	return 0;
}