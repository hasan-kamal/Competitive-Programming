#include <stdio.h>
typedef long long int ll;

int main(){

	ll t, k, n, i;
	scanf("%lld", &t);

	int firstWins;
	while(t--){
		scanf("%lld %lld", &k, &n);

		if( ((n-1)%3!=0) )
			printf("Yes\n");
		else{
			if(k%2==0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}