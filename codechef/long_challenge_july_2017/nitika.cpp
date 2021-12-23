/*

@author Hasan Kamal

*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string capitalize(string s){
	string ans = "";
	for(char& ch : s){
		ans += (ch >= 'A' && ch <= 'Z' ? ch - 'A' + 'a' : ch);
	}
	ans[0] = (s[0] >= 'a' && s[0] <= 'z' ? s[0] - 'a' + 'A' : s[0]);
	return ans;
}

string shorten(string s){
	string ans = "";
	ans += (s[0] >= 'a' && s[0] <= 'z' ? s[0] - 'a' + 'A' : s[0]);
	ans += ".";
	return ans;
}

int main(){

	int t;
	cin >> t;

	string str;
	vector<string> vs;
	getline(cin, str);
	while(t--){
		getline(cin, str);
		istringstream iss(str);
		vs = vector<string>();
		
		string w;
		int num_words = 0;
		while(iss >> w){
			vs.push_back(w);
			num_words++;
		}

		vector<string> ans = vector<string>(num_words);
		ans[num_words - 1] = capitalize(vs[num_words - 1]);

		for(int i = num_words - 2; i >= 0; i--){
			ans[i] = shorten(vs[i]);
		}

		for(string& s : ans)
			cout << s << " ";
		cout << endl;
	}

	return 0;
}