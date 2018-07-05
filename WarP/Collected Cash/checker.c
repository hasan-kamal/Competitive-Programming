#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define T_MAX 101
#define N_MAX 10001
#define A_MAX 1000000000

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

int n_s[N_MAX];
int a_in[T_MAX][N_MAX];
int a_out[T_MAX][N_MAX];

int checkAnswer(int in[][N_MAX], int out[][N_MAX], int x, int n){
	
	//check if alternating
	int isFine = 1;

	int i;
	for(i=0; i<n; i++){

		if(i==n-1)
			continue;

		if(i%2==0){
			if(out[x][i]<out[x][i+1]){
				isFine = 0;
				break;
			}
		}else{
			if(out[x][i]>out[x][i+1]){
				isFine = 0;
				break;
			}
		}
	}

	if(!isFine)
		return 0;

	//check if values are same
	merge_sort(in[x], 0, n-1);
	merge_sort(out[x], 0, n-1);

	for(i=0; i<n; i++){
		if(in[x][i]!=out[x][i])
			return 0;
	}

	return 1;
}

int main(){

	//get input
	int t, n;
	scanf("%d", &t);
	int i, j;
	for(i=0; i<t; i++){
		scanf("%d", &n);
		n_s[i] = n;
		for(j=0; j<n; j++)
			scanf("%d", &a_in[i][j]);
	}

	//get output
	for(i=0; i<t; i++){
		for(j=0; j<n_s[i]; j++)
			scanf("%d", &a_out[i][j]);
	}

	//check answer
	for(i=0; i<t; i++){
		assert(checkAnswer(a_in, a_out, i, n_s[i]));
	}

	return 0;
}