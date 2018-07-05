/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <sstream>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	string s;
	getline(cin, s);
		
	while(t--){
		getline(cin, s);
		istringstream is(s);
		
		vi a = vi();
		int x;
		while(is >> x){
			a.pb(x);
		}
		
		int n = a.size();
		bool has_skipped = false;

		int max = -1;
		for(int i = 0; i < n; i++){
			if(!has_skipped && a[i] == n - 1){
				has_skipped = true;
				continue;
			}

			if(a[i] > max)
				max = a[i];
		}

		cout << max << endl;
	}		

	return 0;
}