#include <iostream>
using namespace std;

typedef long long int ll;

ll t(ll n){
	if(n==2)
		return 1;
	else
		return (n-1)*t(n-2) + n;
}

int main(){

	//cout<<t(16)<<endl;
	cout<<(1<<3)<<endl;

	return 0;
}