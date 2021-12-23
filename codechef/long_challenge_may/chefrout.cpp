#include <iostream>
#include <regex>
using namespace std;

int main(){

	int t;
	string s;
	cin>>t;

	regex r("C*E*S*");
	while(t--){
		cin>>s;
		if(regex_match(s, r))
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	
	return 0;
}