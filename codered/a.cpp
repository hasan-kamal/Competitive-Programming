#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int l;
		cin >> l;

		string s;
		cin >> s;

		string target = "codered";

		int f = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == target[f]){
				f++;
				if(f >= target.length())
					break;
			}
		}

		if(f >= target.length())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}

	return 0;
}