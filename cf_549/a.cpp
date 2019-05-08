#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int l = 0;
	int r = 0;

	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i])
			r++;
		else
			l++;
	}

	int l_ = 0;
	int r_ = 0;
	for(int i = 0; i < n; i++){
		if(a[i])
			r_++;
		else
			l_++;

		if(l_ >= l){
			cout << i + 1;
			return 0;
		}

		if(r_ >= r){
			cout << i + 1;
			return 0;	
		}
	}

	return 0;
}