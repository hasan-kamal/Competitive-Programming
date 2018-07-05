#include <iostream>
using namespace std;

int is_prime(int x){
	if(x<2)
		return false;
	bool is_prime = true;
	for(int i=2; i*i<=x; i++){
		if(x%i==0){
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

int main(){

	int t, n, m;
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i=m; i<=n; i++)
			if(is_prime(i))
				cout<<i<<endl;
	}

	return 0;
}