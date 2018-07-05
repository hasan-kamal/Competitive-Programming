#include <stdio.h>

int main(){

	int t, l1, l2, w1, w2;

	int min, max;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %d %d", &l1, &w1, &l2, &w2);

		max = l1*w1 + l2*w2;
		if(w1>w2){

			if(l1>l2)
				min = w1*l1;
			else
				min = max - w2*l1;

		}else{

			if(l1>l2)
				min = max - w1*l2;
			else
				min = l2*w2;

		}

		printf("%d %d\n", min, max);
	}

	return 0;
}