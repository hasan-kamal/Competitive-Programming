#include <iostream>
#include <vector>
#define N (2*1e4 + 1)

typedef long long int ll;
using namespace std;

int main(){

	ll t, n, sum1, sum2;
	vector<ll> x(N), y(N);

	cin>>t;
	while(t--){
		cin>>n;
		for(ll i=0; i<n; i++)
			cin>>x[i];
		for(ll i=0; i<n; i++)
			cin>>y[i];

		sum1 = sum2 = 0;
		for(ll i=0; i<n; i++){
			if(i%2==0){
				sum1+=x[i];
				sum2+=y[i];
			}else{
				sum2+=x[i];
				sum1+=y[i];
			}
		}

		cout<<(sum1<sum2?sum1:sum2)<<endl;
	}

	return 0;
}