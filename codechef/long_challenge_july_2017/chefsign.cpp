/*

@author Hasan Kamal

*/

#include <iostream>
#include <string>
using namespace std;

int main(){

	int t;
	cin >> t;

	string str;
	while(t--){
		cin >> str;

		int max_height = 0;
		int height = 0;

		bool upward_state = true;
		for(char& ch : str){
			if(ch == '>'){
				upward_state = false;
				break;
			}else if(ch == '<'){
				upward_state = true;
				break;
			}
		}
			
		int n = str.length();
		for(int i = 0; i < n; i++){
			char ch = str[i];

			if(ch == '<'){
				
				if(upward_state)
					height++;
				else{
					height = 1;
					upward_state = true;
				}

			}else if(ch == '>'){

				if(!upward_state)
					height++;
				else{
					height = 1;
					upward_state = false;
				}

			}

			if(height > max_height)
				max_height = height;
		}

		cout << max_height + 1 << endl;
	}

	return 0;
}