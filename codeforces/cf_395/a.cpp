/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>

using namespace std;

int gcdf(int n, int m){
	if(n<m){
		int temp = n;
		n = m;
		m = temp;
	}
	int rem = n%m;
	while(rem){
		n = m;
		m = rem;
		rem = n%m;
	}
	return m;
}

int main(){

	int n, m, z;
	cin>>n>>m>>z;
	int gcd = gcdf(n, m);
	int lcm = n*m/gcd;
	cout<<z/lcm;

	return 0;
}