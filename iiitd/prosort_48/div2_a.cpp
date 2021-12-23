/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

	int t, n;
	cin>>t;

	while(t--){
		cin>>n;

		int ans=0, s1, s2, s3;
		for(int i=1; i<n; i++)
			for(int j=i+1; j<n; j++){
				s1 = i;
				s2 = j-i;
				s3 = n-j;
				if(s1+s2>s3 && s1+s3>s2 && s2+s3>s1)
					ans++;
			}

		cout<<ans<<endl;
	}	
	
	return 0;
}