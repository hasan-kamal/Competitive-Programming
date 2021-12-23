/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define LEN 20
typedef long long int ll;

bool is_tidy(ll n){
	int dig = 9;
	int new_dig;
	while(n!=0){
		
		new_dig = n%10;
		n/=10;

		if(new_dig>dig)
			return false;

		dig = new_dig;
	}

	return true;
}

int main(){

	ll t, n;
	char str[20];

	scanf("%lld", &t);

	for(ll i=0; i<t; i++){
		scanf("%lld", &n);

		while(!is_tidy(n))
			n--;
		
		printf("Case #%lld: ", i+1);
		printf("%lld\n", n);
	}

	return 0;
}