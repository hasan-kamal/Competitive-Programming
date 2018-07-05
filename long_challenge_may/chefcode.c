#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#define N 35

typedef long long int ll;
double a_logs[N];
double l_k;
int n;

int calc_subs(int index, double old_sum){
	if(index==n-1){
		int ans = 0;
		
		if(old_sum+a_logs[index]<=l_k){
			ans++;
		}

		if(old_sum<=l_k){
			//don't take last element
			ans++;
		}

		return ans;
	}

	if(old_sum>l_k){
		return 0;
	}

	int ans = 0;
	if(old_sum+a_logs[index]<=l_k)
		ans+=calc_subs(index+1, old_sum+a_logs[index]);
	ans+=calc_subs(index+1, old_sum);

	return ans;
}

int exp_2(int p){
	if(p==0)
		return 1;
	else if(p==1)
		return 2;
	else{
		if(p%2==0)
			return exp_2(p/2)*exp_2(p/2);
		else
			return exp_2(p-1)*2;
	}
}

int calc_subs2(int index, double l_k){

	if(l_k<0)
		return 0;

	if(index==0){
		int ans = 1;
		if(a_logs[index]<=l_k)
			ans++;
		return ans;
	}

	if((index+1)*a_logs[index]<l_k){
		//printf("hello");
		int ans = exp_2(index+1);
		return ans;
	}

	return calc_subs2(index-1, l_k) + calc_subs2(index-1, l_k-a_logs[index]);
}


double t1[N];
double t2[N];
void merge(int p, int q, int r){
	int i;
	for(i=p; i<=q; i++)
		t1[i-p] = a_logs[i];
	t1[i-p] = DBL_MAX;

	for(i=q+1; i<=r; i++)
		t2[i-q-1] = a_logs[i];
	t2[i-q-1] = DBL_MAX;

	int x1=0;
	int x2=0;
	for(i=p; i<=r; i++){
		if(t1[x1]<t2[x2]){
			a_logs[i] = t1[x1];
			x1++;
		}else{
			a_logs[i] = t2[x2];
			x2++;
		}
	}
}

void sort(int low, int high){
	if(low<high){
		int mid = low + (high-low)/2;
		sort(low, mid);
		sort(mid+1, high);
		merge(low, mid, high);
	}
}

int main(){

	ll k;
	scanf("%d %lld", &n, &k);

	ll temp;
	int i;
	for(i=0; i<n; i++){
		scanf("%lld", &temp);
		a_logs[i] = log((double)temp);
	}

	sort(0, n-1);
	l_k = log((double)k);
	int ans = calc_subs2(n-1, l_k);
	//int ans = calc_subs(0, 0.0);
	printf("%d", ans-1);

	return 0;
}