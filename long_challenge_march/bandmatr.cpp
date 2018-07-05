#include <iostream>
#include <vector>

#define N 501

using namespace std;

int main(){

	int t, n, num_one, temp;
	
	cin>>t;
	while(t--){
		cin>>n;
		num_one = 0;
		for(int i=0; i<n*n; i++){
			cin>>temp;
			if(temp)
				num_one++;
		}

		for(int k=0; k<=n; k++){
			if(num_one-n<=k*(2*n-k-1)){
				cout<<k<<endl;
				break;
			}
		}
	}

	return 0;
}