#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 1000000;
char arr[MAX];
int ai[MAX];

int getval(char a){
	return ('z'-a)%10;
}

void print_array(int a[MAX], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main(){

	int t, n, curNum, num_numbers, sum_sum_all_dig, ans,csum, k=0;
	cin>>t;


	while(t--){
		cin>>arr;
		n=strlen(arr);

		num_numbers=0;
		curNum=0;
		sum_sum_all_dig=0;
		ans=0;
		k=0;
		for(int i=0; i<=n; i++){

			if(arr[i]=='_' || arr[i]=='\0'){
				//ai[num_numbers++]=curNum;
				curNum=0;
				csum=sum_sum_all_dig-k;
				ai[num_numbers++]=csum;
				k=sum_sum_all_dig;
				
			}else{

				curNum=curNum*10+getval(arr[i]);
				sum_sum_all_dig+=getval(arr[i]);

			}

		}


		for(int x=0; x<num_numbers; x++){
			if(ai[x]!=0){
				if(sum_sum_all_dig%ai[x]==0){
					ans+=ai[x];
				}
			}
		}


		cout<<ans<<endl;
		//print_array(ai, num_numbers);

	}

	return 0;
}