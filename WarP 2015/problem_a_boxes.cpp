#include <iostream>
using namespace std;

const int MAX = 100002;

void print_array(int a[MAX], int n){
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void merge(int a[MAX], int start, int mid, int end){
	int i=start;
	int j=mid+1;
	int c[MAX], k=0;

	while(i<=mid&&j<=end){
		if(a[i]<a[j]){
			c[k++]=a[i];
			i++;
		}else{
			c[k++]=a[j];
			j++;
		}
	}

	while(i<=mid){
		c[k++]=a[i];
		i++;
	}

	while(j<=end){
		c[k++]=a[j];
		j++;
	}

	for(int alpha=0; alpha<k; alpha++){
		a[start+alpha]=c[alpha];
	}
}

void mergesort(int a[MAX], int start_index, int end_index){
	int mid;
	if(start_index==end_index){

	}else{
		mid=(start_index+end_index)/2;
		mergesort(a, start_index, mid);
		mergesort(a, mid+1, end_index);
		merge(a, start_index, mid, end_index);
	}
}


int main(){
	
	int n, temp, a[MAX], z=0;
	cin>>n;

	while(n--){
		cin>>temp;
		a[z++]=temp;
	}

	//print_array(a, i);
	mergesort(a, 0, z-1);
	//print_array(a, z);

	bool is_possible = true;

	for(int i=z-1; i>=0; i--){
		//cout<<a[i]<<":"<<i<<endl;
		if(a[i]<i){
			is_possible=false;
			break;
		}
	}

	if(is_possible)
		cout<<"Yes";
	else
		cout<<"No";
}

















