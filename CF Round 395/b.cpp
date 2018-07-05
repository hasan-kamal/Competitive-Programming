/*

@author Hasan Kamal

*/
#include <iostream>
#include <vector>
using namespace std;

void swp(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

int main(){
	
	int n;
	cin>>n;

	vector<int> v(n);
	for(int i=0; i<n; i++)
		cin>>v[i];

	if(n%2==0){
		int i;
		if((n/2)%2==0)
			i=1;
		else
			i=0;
		for(; n/2-1-i>=0; i+=2)
			swp(v[n/2-1-i], v[n/2+i]);
		// for(int i=0; i<=n-1-i; i++)
		// 	swp(v[i], v[n-1-i]);s
	}else{
		int i;
		if(((n-1)/2)%2==0)
			i=2;
		else
			i=1;
		for(; n/2-i>=0; i+=2)
			swp(v[n/2-i], v[n/2+i]);
	}

	for(int x : v)
		cout<<x<<" ";

	return 0;
}