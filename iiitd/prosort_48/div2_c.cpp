/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

#define B_MAX 1000002
int arr[B_MAX];

int main(){

	int t, n;
	cin>>t;

	int a, b;
	while(t--){
		cin>>n;

		for(int i=0; i<B_MAX; i++)
			arr[i] = 0;

		for(int i=0; i<n; i++){
			cin>>a>>b;
			arr[a]++;
			arr[b+1]--;
		}

		int sum=0, max = -1;
		for(int i=0; i<B_MAX; i++){
			sum+=arr[i];
			if(sum>max)
				max = sum;
		}

		cout<<max<<endl;
	}	
	
	return 0;
}