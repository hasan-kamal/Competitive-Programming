#include <iostream>
using namespace std;

int main(){

	int t, m, n, ans;
	cin>>t;
	while(t--){
		cin>>m>>n;

		if(n<2 || m<2){
			ans=m*n;
		}else if(n==2){

			if((m-1)%4==0){
				ans=m+1;
			}else{
				ans = ((m+3)/4)*4;
			}

		}else{

			if(n%2==0 || m%2==0){
				ans=(n*m)/2;
			}else{
				ans=((n*m)+1)/2;
			}

		}

		cout<<ans<<endl;

	}

	return 0;
}