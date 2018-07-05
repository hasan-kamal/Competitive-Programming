#include <stdio.h>
#include <limits.h>
#define M 100005

void merge(int *a, int p, int q, int r){
	int temp1[M], temp2[M];
	int i;

	for(i=p; i<=q; i++)
		temp1[i-p] = a[i];
	temp1[i-p] = INT_MAX;

	for(i=q+1; i<=r; i++)
		temp2[i-q-1] = a[i];
	temp2[i-q-1] = INT_MAX;

	int x1=0, x2=0;
	for(i=p; i<=r; i++){
		if(temp1[x1]<temp2[x2]){
			a[i] = temp1[x1];
			x1++;
		}else{
			a[i] = temp2[x2];
			x2++;
		}
	}
	
}

void merge_sort(int *a, int low, int high){
	if(low<high){
		merge_sort(a, low, (low+high)/2);
		merge_sort(a, (low+high)/2+1, high);
		merge(a, low, (low+high)/2, high);
	}
}

int main(){

	int m, n;
	int a[M];

	scanf("%d %d", &m, &n);
	int i;
	for(i=0; i<m; i++)
		scanf("%d", &a[i]);

	merge_sort(a, 0, m-1);

	int sum = 0;
	int count = 0;
	for(i=0; i<m; i++){
		if(sum+a[i]<=n){
			sum+=a[i];
			count++;
		}else
			break;
	}

	printf("%d", count);

	return 0;
}