/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){

	int n;
	cin>>n;

	vi a = vi(n);
	for(int i=0; i<n; i++)
		cin>>a[i];

	sort(a.begin(), a.end());
	for(int i=0; i<=n-1-i; i++){
		cout<<a[i]<<" ";
		if(i!=n-1-i)
			cout<<a[n-1-i]<<" ";
	}

	return 0;
}