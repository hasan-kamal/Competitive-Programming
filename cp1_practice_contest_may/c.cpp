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

	vi marks = vi(n);
	int max_so_far = a[n-1];
	int max_ascension_so_far = INT_MIN;
	marks[n-1] = 15;

	for(int i=n-2; i>=0; i--){
		if(a[i]<max_ascension_so_far)
			marks[i] = 5;
		else if(a[i]>=max_so_far)
			marks[i] = 15;
		else
			marks[i] = 10;

		if(a[i]>a[i+1]){
			if(a[i]>max_ascension_so_far)
				max_ascension_so_far = a[i];
		}

		if(a[i]>max_so_far)
			max_so_far = a[i];
	}

	int ans = 0;
	for(int i=0; i<n; i++)
		ans+=marks[i];
	cout<<ans;

	return 0;
}