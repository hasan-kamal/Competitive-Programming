/*

@author Hasan Kamal

*/
#include <iostream>
#include <vector>
#define N int(1000005)

using namespace std;

void copyvec(vector<int> &dest, const vector<int> &source, int n){
	for(int i=0; i<n; i++)
		dest[i] = source[i];
}

vector<int> b(N);
bool p(int max_bsize, const vector<int> &a, int n, int k){
	if(max_bsize>1){

		copyvec(b, a, n);
		int count = 0;
		int num_consec = 1;
		for(int i=1; i<n; i++){
			if(b[i]==b[i-1])
				num_consec++;
			else
				num_consec = 1;

			if(num_consec>max_bsize){
				if(i+1<n && b[i+1]==b[i]){
					//make flip at ith position
					b[i] = 1-b[i];
				}else{
					//make flip at i-1 th position
					b[i-1] = 1-b[i-1];
				}

				count++;
				num_consec=1;
			}
		}
		return count<=k;

	}else{

		//max_b_size==1

		//without flipping 0th pos
		copyvec(b, a, n);
		int count = 0;
		for(int i=1; i<n; i++){
			if(b[i]==b[i-1]){
				b[i] = 1-b[i];
				count++;
			}
		}
		if(count<=k)
			return true;

		//with flipping at 0th pos
		copyvec(b, a, n);
		count = 1;
		b[0] = 1-b[0];
		for(int i=1; i<n; i++){
			if(b[i]==b[i-1]){
				b[i] = 1-b[i];
				count++;
			}
		}
		return count<=k;

	}
}

int main(){

	int t, k, n;
	vector<int> a(N);
	char str[N];

	int lo, hi, mid;

	cin>>t;
	while(t--){
		cin>>n>>k;

		scanf("%s", str);
		for(int i=0; i<n; i++)
			a[i] = (str[i] -'0');

		lo = 1;
		hi = n+1;
		while(lo<hi){
			mid = lo + (hi-lo)/2;
			if(p(mid, a, n, k))
				hi = mid;
			else
				lo = mid+1;
		}

		cout<<lo<<endl;
	}

	return 0;
}