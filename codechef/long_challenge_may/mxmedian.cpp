#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 50001
typedef vector<int> vi;

int main(){

	int t;
	cin>>t;

	int n;
	vi a(2*N, 0);
	while(t--){
		cin>>n;
		for(int i=0; i<2*n; i++)
			cin>>a[i];
		sort(a.begin(), a.begin()+2*n);
		int b = a[(3*n1-)/2];
		cout<<b<<endl;
		for(int i=0; i<n; i++){
			cout<<a[i]<<" "<<a[n+i]<<" ";
		}
		cout<<endl;
	}

	return 0;
}