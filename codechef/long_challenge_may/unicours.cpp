#include <iostream>
#include <vector>
using namespace std;

#define N 100002
typedef vector<int> vi;

int main(){

	int t, n;
	vi a(N, 0);

	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1; i<=n; i++)
			cin>>a[i];

		int ans = 0, oc;
		for(int k=1; k<=n; k++){
			oc = k-1-ans;
			if(oc<a[k])
				ans = k-1-a[k];
			ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}