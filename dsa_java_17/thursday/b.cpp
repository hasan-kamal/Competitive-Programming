/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	stack<char> st = stack<char>();
	for(int i = 0; i < n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			cout << s[i];
		}else{
			if(s[i] == '('){
				push
			}
		}
	}

	return 0;
}