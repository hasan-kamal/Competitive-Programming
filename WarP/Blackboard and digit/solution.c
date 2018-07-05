#include <stdio.h>

int numDigits(int n){
	int numDigits = 1;
	while(n/10){
		numDigits++;
		n/=10;
	}
	return numDigits;
}

int nines[11] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};

int power(int base, int exp){
	int ans = 1;
	while(exp--)
		ans*=base;
	return ans;
}

int sub(int *a, int low, int high){
	int n = high - low + 1;
	if(low==high){
		if(a[low]>3)
			return 1;
		else
			return 0;
	}else{
		if(a[low]<3){
			return a[low]*sub(nines, 1, n-1) + sub(a, low+1, high);
		}else{
			return (a[low]-1)*sub(nines, 1, n-1)  + sub(a, low+1, high) + power(10, n-1);
		}
	}
}

int main(){

	int t, n;
	scanf("%d", &t);

	int a[11], i, temp;

	while(t--){
		scanf("%d", &n);

		temp = n;
		for(i=numDigits(n)-1; i>=0; i--){
			a[i] = temp%10;
			temp/=10;
		}

		printf("%d\n", n-sub(a, 0, numDigits(n)-1));
	}

	return 0;
}