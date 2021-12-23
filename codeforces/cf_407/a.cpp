/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin>>n>>k;

	vi w(n);
	for(int i=0; i<n; i++){
		cin>>w[i];
		w[i] = (w[i]%k==0)?(w[i]/k):(w[i]/k + 1);
	}

	int sum=0;
	for(int i=0; i<n; i++)
		sum+=w[i];
	if(sum%2==0)
		sum/=2;
	else
		sum=(sum)/2+1;

	cout<<sum;

	return 0;
}
