/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

int main(){

	int s;
	cin>>s;

	int n;
	vector<int> strip_length;
	while(s--){
		cin>>n;
		strip_length = vector<int>(n);
		for(int i=0; i<n; i++)
			cin>>strip_length[i];

		bool is_valid = true;
		if(n%2==0 || strip_length[0]!=1 || strip_length[n-1]!=1)
			is_valid = false;

		if(!is_valid){
			cout<<"no"<<endl;
			continue;
		}

		int centre_index = n/2;
		for(int i=0; i<centre_index; i++){
			if(strip_length[i]+1!=strip_length[i+1]){
				is_valid = false;
				break;
			}
		}

		if(!is_valid){
			cout<<"no"<<endl;
			continue;
		}

		for(int i=centre_index; i<n-1; i++){
			if(strip_length[i]-1!=strip_length[i+1]){
				is_valid = false;
				break;
			}
		}

		if(!is_valid){
			cout<<"no"<<endl;
		}else
			cout<<"yes"<<endl;
	}

	return 0;
}