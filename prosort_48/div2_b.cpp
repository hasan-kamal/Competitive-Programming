/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

int f(int n, int m){
	if(n<=0 || m<=0)
		return 0;
	else if(n<=1 && m<=1)
		return 0;
	else if(n==2 && m==1)
		return 1;
	else if(n==1 && m==2)
		return 1;
	else if(n>m)
		return 1 + f(n-2, m-1);
	else
		return 1 + f(n-1, m-2);
}

int main(){

	int n, m;
	cin>>n>>m;
	cout<<f(n, m);
	
	return 0;
}