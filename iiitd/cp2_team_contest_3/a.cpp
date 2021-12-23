/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

bool is_pal(string &str, int s, int e){
	for(int i = 0; s + i <= e; i++){
		if(str[s + i] != str[e - i])
			return false;
	}
	return true;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	bool flag = true;
	int n = s.length();
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if(is_pal(s, i, j) && (j - i + 1) % 2 == 0){
				flag = false;
				break;
			}
		}
		if(!flag)
			break;
	}

	cout << (flag ? "Odd." : "Or not.");

	return 0;
}