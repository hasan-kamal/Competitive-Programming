#include <stdio.h>
#include <limits.h>
#define N_MAX 100005

//int x1[N_MAX];
//int x2[N_MAX];

void merge(int *a, int p, int q, int r){
	int x1[N_MAX], n1=q-p+1;
	int x2[N_MAX], n2=r-q;

	// int n1 = q-p+1;
	// int n2 = r-q;

	int i;
	for(i=p; i<=q; i++)
		x1[i-p] = a[i];
	x1[i-p] = INT_MAX;

	for(i=q+1; i<=r; i++)
		x2[i-q-1] = a[i];
	x2[i-q-1] = INT_MAX;

	int i1=0, i2=0;
	//with sentinel
	for(i=p; i<=r; i++){
		if(x1[i1]<=x2[i2]){
			a[i] = x1[i1];
			i1++;
		}else{
			a[i] = x2[i2];
			i2++;
		}
	}
}

void merge_sort(int *a, int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int main(){

	int t, n, a[N_MAX];
	scanf("%d", &t);

	int i;
	while(t--){
		scanf("%d", &n);

		for(i=0; i<n; i++)
			scanf("%d", &a[i]);

		merge_sort(a, 0, n-1);

		for(i=0; i<n; i+=2){
			if(i+1<n)
				printf("%d ", a[i+1]);
			printf("%d ", a[i]);
		}

		printf("\n");
	}

	return 0;
}