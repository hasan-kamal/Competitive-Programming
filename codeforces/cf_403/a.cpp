/*

@author Hasan Kamal

*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;

int main(){

	int n;
	cin>>n;

	vi v(2*n);
	for(int i=0; i<2*n; i++)
		cin>>v[i];

	vi x(n+1, 0);
	int table_count = 0;
	int max = -1;
	for(int i=0; i<2*n; i++){
		if(x[v[i]]==0){
			table_count++;
			x[v[i]] = 1;
		}else{
			x[v[i]] = 0;
			table_count--;
		}

		if(table_count>max)
			max = table_count;
	}

	cout<<max;

	return 0;
}