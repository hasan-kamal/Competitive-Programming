#include <iostream>
#include <vector>
#include<string>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.length();
	vi stack = vi(n);
	int index = 0;
	int count = 0;
	for(int i = 0; i < n; i++){
		if(index - 1 >= 0){
			if(s[i] == stack[index - 1]){
				index--;
				count++;
			}else{
				stack[index++] = s[i];	
			}
		}else{
			stack[index++] = s[i];
		}
	}

	if((count & 1) == 0)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}