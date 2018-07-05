#include <stdio.h>
#define D_MAX 100000
#define T_MAX 1000000

typedef long long ll;

typedef struct{
	ll n_t, t;
} node;

node t1[D_MAX];
node t2[D_MAX];
node SENTINEL = {0, T_MAX+5};
void merge_node(node *a, ll p, ll q, ll r){
	ll i;
	for(i=p; i<=q; i++)
		t1[i-p] = a[i];
	t1[i-p] = SENTINEL;

	for(i=q+1; i<=r; i++)
		t2[i-q-1] = a[i];
	t2[i-q-1] = SENTINEL;

	ll x1=0;
	ll x2=0;
	for(i=p; i<=r; i++){
		if(t1[x1].t<t2[x2].t){
			a[i] = t1[x1];
			x1++;
		}else{
			a[i] = t2[x2];
			x2++;
		}
	}
}

void merge_sort_node(node *a, ll low, ll high){
	if(low<high){
		merge_sort_node(a, low, (low+high)/2);
		merge_sort_node(a, (low+high)/2+1, high);
		merge_node(a, low, (low+high)/2, high);
	}
}

long long p(long long x, node *arr, long long d, long long k){
	long long sum = 0;
	long long n_open = 1;
	long long i;
	for(i=0; i<d; i++){
		if(sum+arr[i].n_t>x){
			n_open++;
			sum = arr[i].n_t;
		}else{
			sum+=arr[i].n_t;
		}
	}

	if(n_open<=k)
		return 1;
	else
		return 0;
}

int main(){

	ll k, d, t, n, i;
	scanf("%lld", &k);
	scanf("%lld", &d);

	node arr[D_MAX];
	long long max_n = -1;
	long long summation_n = 0;
	for(i=0; i<d; i++){
		scanf("%lld %lld", &t, &n);
		arr[i].n_t = n;
		arr[i].t = t;
	
		if(n>max_n)
			max_n = n;

		summation_n = summation_n + n;
	}

	merge_sort_node(arr, 0, d-1);

	//binary search begins
	long long lo = max_n;
	long long hi = summation_n;
	long long mid;
	while(lo<hi){
		mid = lo + (hi-lo)/2;
		if(p(mid, arr, d, k))
			hi = mid;
		else
			lo = mid+1;
	}

	if(p(lo, arr, d, k))
		printf("%lld", lo);
	else
		printf("ERROR!");


	return 0;
}