/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

#define LEN 30
typedef long long int ll;

int main(){

	ll t, length, ans;
	char str[LEN];

	scanf("%lld", &t);

	for(ll i=0; i<t; i++){
		scanf("%s\n", str);
		length = strlen(str);

		for(ll j=length-2; j>=0; j--){
			if(str[j]>str[j+1]){
				str[j]--;
				for(ll x=j+1; x<length; x++)
					str[x] = '9';
			}
		}

		ll ind = 0;
		while(str[ind]=='0')
			ind++;

		printf("Case #%lld: ", i+1);
		printf("%s\n", str+ind);
	}

	return 0;
}