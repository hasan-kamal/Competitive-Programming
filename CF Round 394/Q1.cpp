#include <iostream>
#include <vector>
using namespace std;

int main(){
	
	int a, b;
	cin>>a>>b;

	if((a==0) && (b==0)){
		cout<<"NO";
		return 0;
	}

	int d = a-b;
	if( (d==0)||(d==1)||(d==-1) )
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}