#include <stdio.h>
#include <assert.h>
#define T_MAX 100000
#define K_MAX 100000
#define C_MAX 100000

int main(){

	int t, k, c;
	scanf("%d", &t);
	assert(1<=t && t<=T_MAX);

	while(t--){
		scanf("%d %d", &k, &c);
		printf("%d\n", 2*k+c-1);

		assert(1<=k && k<=K_MAX);
		assert(1<=c && c<=C_MAX);
	}

	return 0;
}