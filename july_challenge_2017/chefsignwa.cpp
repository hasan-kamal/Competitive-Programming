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
 
		int max_height = 1;
		int height = 1;
		bool upward_state = (str[0] == '<' ? true : false);
		
		for(char& ch : str){
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
 
		cout << max_height << endl;
	}
 
	return 0;
} 