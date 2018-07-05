#include <iostream>
using namespace std;

int main(){


	int t, n, a, temp;
	cin>>t;

	char ch;

	while(t--){

		cin>>n;
		for(int i=0; i<n; i++){
			if(i==0)
				cin>>a;
			else{
				cin>>temp;
				a=a^temp;
			}
		}

		cout<<a<<endl;
	
	}


	return 0;
}