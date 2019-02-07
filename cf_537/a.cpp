#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

bool is_vowel(char a){
	if( (a == 'a')  || (a == 'e')  ||(a == 'i')  ||(a == 'o')  || (a == 'u'))
		return true;
	return false;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s, t;
	cin >> s;
	cin >> t;

	if(s.length() != t.length()){
		cout << "No";
		return 0;
	}

	for(int i = 0; i < s.length(); i++){
		if(is_vowel(s[i]) ^ is_vowel(t[i])){
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	
	return 0;
}