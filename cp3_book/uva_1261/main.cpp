#include <iostream>
#include <map>
using namespace std;

typedef map<string, bool> msb;
msb m;

bool reducible(string s){
	if(m.find(s) != m.end())
		return m[s];

	if(s.empty()){
		m[s] = true;
		return true;
	}

	for(int i = 0; i < (int)s.length(); i++){
		int j;
		for(j = i + 1; j < (int)s.length() && s[j] == s[i]; j++);
		if(j - i >= 2){
			if(reducible(s.substr(0, i) + s.substr(j))){
				m[s] = true;
				// cout << s << " " << m[s] << endl;
				return true;
			}
			i = j - 1;
		}
	}

	m[s] = false;
	// cout << s << " " << m[s] << endl;
	return false;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	m = msb();
	string s;
	while(t--){
		cin >> s;
		cout << reducible(s) << endl;
	}

	return 0;
}