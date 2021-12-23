/*

@author Hasan Kamal

*/

#include <iostream>
using namespace std;

int main(){

	int r;
	cin>>r;
	
	int n;
	string str;
	
	while(r--){
		cin>>n;
		cin>>str;

		bool printed = false;
		bool last_t = true;

		for(char ch : str){
			if(ch=='.')
				continue;
			else if(last_t && ch=='T'){
				cout<<"Invalid"<<endl;
				printed = true;
				break;
			}else if(!last_t && ch=='H'){
				cout<<"Invalid"<<endl;
				printed = true;
				break;
			}else
				last_t = !last_t;
		}

		if(!printed){
			if(last_t)
				cout<<"Valid"<<endl;
			else
				cout<<"Invalid"<<endl;
		}
	}

	return 0;
}