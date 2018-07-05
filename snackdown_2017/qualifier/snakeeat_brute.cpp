/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
vi l;
vii running_sums;
vi total_running_sums;
int running_sums_size;

int query(int k, int n){
	
	//binary search on l array
	int lo = 0;
	int hi = n-1;
	int mid;
	while(lo<hi){
		mid = lo + (hi-lo+1)/2;
		if(l[mid]>=k)
			hi = mid-1;
		else
			lo = mid;
	}
	int longest_unselected_snake_ind = lo;
	//cout<<"hello"<<longest_unselected_snake_ind<<endl;
	if(l[lo]>=k){
		return n;
	}

	//binary search on running_sums array
	lo = 0;
	hi = running_sums_size - 1;
	while(lo<hi){
		mid = lo + (hi-lo+1)/2;
		if(running_sums[mid].first>=k)
			hi = mid-1;
		else
			lo = mid;
	}
	int largest_unselected_value_index = lo;

	int ans = n-1- longest_unselected_snake_ind;
	//ans+=f(largest_unselected_value_index, total_running_sums[largest_unselected_value_index], k, n);
	
	// following causes TLE
	int a = -1;
	int b = longest_unselected_snake_ind;
	while(k-l[b]<=b-a-1){
		a+=(k-l[b]);
		b--;
		ans++;
	}

	return ans;
}

int main(){

	int t, n, q, k;
	cin>>t;

	while(t--){

		cin>>n>>q;
		l = vi(n);
		
		for(int i=0; i<n; i++)
			cin>>l[i];
		sort(l.begin(), l.end());

		int last_val = l[0];
		int sum = 0;
		running_sums = vii();
		running_sums_size = 0;
		for(int i=0; i<n; i++){
			if(l[i]>last_val){
				running_sums.push_back(make_pair(last_val, sum));
				running_sums_size++;
				last_val = l[i];
				sum = 1;
			}else
				sum++;
		}
		running_sums.push_back(make_pair(last_val, sum));
		running_sums_size++;

		total_running_sums = vi(running_sums_size, 0);
		total_running_sums[0] = running_sums[0].second;
		for(int i=1; i<running_sums_size; i++)
			total_running_sums[i] = running_sums[i].second + total_running_sums[i-1];

		for(int i=0; i<q; i++){
			cin>>k;
			cout<<query(k, n)<<endl;
		}
	}

	return 0;
}