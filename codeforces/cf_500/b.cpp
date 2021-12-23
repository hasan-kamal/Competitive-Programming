#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;

	vi a = vi(n);
	vi c = vi(100005, 0);
	for(int i = 0; i < n; i++){
		cin >> a[i];	
		c[a[i]]++;
	}

	for(int i = 0; i < 100005; i++){
		if(c[i] > 1){
			cout << 0;
			return 0;
		}
	}

	for(int i = 0; i < n; i++){
		c[a[i]]--;

		if(c[a[i] & x] > 0){
			cout << 1;
			return 0;
		}

		c[a[i]]++;
	}

	// check for 2
	c = vi(100005, 0);
	for(int i = 0; i < n; i++){
		c[a[i] & x]++;
	}
	for(int i = 0; i < 100005; i++){
		if(c[i] > 1){
			cout << 2;
			return 0;
		}
	}

	cout << -1;

	return 0;
}