/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<char, string> m;
	m['p'] = "Power";
	m['g'] = "Time";
	m['b'] = "Space";
	m['o'] = "Soul";
	m['r'] = "Reality";
	m['y'] = "Mind";

	vector<char> v;
	while(n--){
		string s;
		cin >> s;
		char ch = s[0];
		v.push_back(ch);
	}

	vector<char> all;
	all.push_back('p');
	all.push_back('g');
	all.push_back('b');
	all.push_back('o');
	all.push_back('r');
	all.push_back('y');

	vector<string> ans;
	int cnt = 0;
	for(char c : all){
		if(find(v.begin(), v.end(), c) == v.end()){
			cnt++;
			ans.push_back(m[c]);
		}
	}

	cout << cnt << endl;
	for(string s : ans)
		cout << s << endl;

	return 0;
}