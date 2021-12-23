/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool not_vowel(char ch){
	if(ch == 'a' || ch == 'o' || ch == 'u' || ch == 'i' || ch == 'e')
		return false;
	return true;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	bool okay = true;
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(s[i] == 'a' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i' || s[i] == 'e'){
			continue;
		}

		if(s[i] == 'n'){
			continue;
		}

		if(i == n - 1 || not_vowel(s[i + 1])){
			okay = false;
			break;
		}
	}

	cout << (okay ? "YES" : "NO");

	return 0;
}