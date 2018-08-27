#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	set<int> st = set<int>();
	for(int i = 0; i < s.length(); i++)
		st.insert(s[i]);

	if(st.size() == 1){
		cout << "Yes";
		return 0;
	}

	vi count = vi(26, 0);
	for(int i = 0; i < s.length(); i++){
		count[s[i] - 'a']++;
	}

	for(int i = 0; i < 26; i++){
		if(count[i] >= 2){
			cout << "Yes";
			return 0;
		}
	}

	cout << "No";

	return 0;
}