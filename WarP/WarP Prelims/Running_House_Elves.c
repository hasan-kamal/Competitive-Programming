#include <stdio.h>

int main(){

	int t, s, v;
	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &s, &v);
		if((2*s)%(3*v)==0){
			printf("%d\n", 2*s/(3*v));
		}else
			printf("%d\n", 2*s/(3*v) + 1);
	}

	return 0;
}