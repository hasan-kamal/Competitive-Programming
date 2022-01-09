#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi> 		vvi;
typedef set<int> 		si;
typedef vector<si>		vsi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n, k;
	vi a;
	vsi s;
	while(t--){
		cin >> n >> k;
		a = vi(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		s = vsi(n, si());
		s[0].insert(a[0] % k);
		for(int i = 1; i < n; i++){
			for(si::iterator it = s[i - 1].begin(); it != s[i - 1].end(); it++){
				s[i].insert((*it + a[i]) % k);
				s[i].insert((*it - a[i] + k) % k);
			}
		}

		if(s[n - 1].find(0) != s[n - 1].end())
			cout << "Divisible";
		else
			cout << "Not divisible";
		cout << endl;
	}

	return 0;
}