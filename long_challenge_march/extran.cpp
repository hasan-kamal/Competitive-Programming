#include <iostream>
#include <vector>
#include <algorithm>
#define N 1e5

using namespace std;

void disp(vector<int> &v, int n){
	for(int i=0; i<n; i++)
		cout<<v[i]<<" ";
	cout<<endl;
}

int main(){

	int t, n, found_answer;
	vector<int> a(N);

	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0; i<n; i++)
			cin>>a[i];

		sort(a.begin(), a.begin()+n);
		
		//disp(a, n);
		found_answer = 0;
		for(int i=0; i<n-1; i++){
			if(a[i]==a[i+1]){
				cout<<a[i]<<endl;
				found_answer = 1;
				break;
			}
		}

		if(!found_answer){
			//remove last element
			if(a[n-2]-a[0]+1==n-1)
				cout<<a[n-1]<<endl;
			else
				cout<<a[0]<<endl;
		}
	}

	return 0;
}