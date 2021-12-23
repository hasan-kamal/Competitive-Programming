#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, temp;
	cin >> n >> k;

	const int M = 200005;
	vi count(M, 0);
	for(int i = 0; i < n; i++){
		cin >> temp;
		count[temp]++;
	}

	int ans = INT_MAX;
	for(int i = M - 1; i >= 0; i--){
		// make k equal number of elements each of value i
		int num_ops = INT_MAX;

		if(num_ops != INT_MAX)
			ans = min(ans, num_ops);
	}

	cout << ans << endl;
	
	return 0;
}