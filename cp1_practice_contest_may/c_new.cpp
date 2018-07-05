/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;

int main(){

	int n;
	cin>>n;

	vi a = vi(n);
	for(int i=0; i<n; i++)
		cin>>a[i];

	vi next_smaller = vi(n);
	vi next_taller = vi(n);
	vi marks = vi(n);
	marks[n-1] = 15;
	next_smaller[n-1] = -1;
	next_taller[n-1] = -1;
	for(int i=n-2; i>=0; i--){
		if(a[i]==a[i+1]){
			next_taller[i] = next_taller[i+1];
			next_smaller[i] = next_smaller[i+1];
		}else if(a[i]>a[i+1]){
			next_smaller[i] = i+1;

			int search_index = i+1;
			while(search_index!=-1 && a[search_index]<=a[i])
				search_index = next_taller[search_index];
			next_taller[i] = search_index;

		}else if(a[i]<a[i+1]){
			next_taller[i] = i+1;

			int search_index = i+1;
			while(search_index!=-1 && a[search_index]>=a[i])
				search_index = next_smaller[search_index];
			next_smaller[i] = search_index;
		}

		if(next_taller[i]==-1)
			marks[i] = 15;
		else if(next_smaller[next_taller[i]]==-1)
			marks[i] = 10;
		else
			marks[i] = 5;
	}

	int ans = 0;
	for(int i=0; i<n; i++)
		ans+=marks[i];
	cout<<ans;

	return 0;
}