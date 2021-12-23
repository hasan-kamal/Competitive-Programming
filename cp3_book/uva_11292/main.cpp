#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	while(cin >> n >> m){
		if(!n && !m)
			return 0;

		vi d(n);
		for(int i = 0; i < n; i++)
			cin >> d[i];

		multiset<int> k;
		int temp;
		for(int i = 0; i < m; i++){
			cin >> temp;
			k.insert(temp);
		}

		// sort(d.rbegin(), d.rend());

		long long int ans = 0;
		bool okay = true;
		for(int i = 0; i < n; i++){
			if(k.empty()){
				okay = false;
				break;
			}

			multiset<int>::iterator it = k.lower_bound(d[i]);
			if(it == k.end()){
				okay = false;
				break;
			}

			ans += *it;
			k.erase(it);
		}

		if(okay)
			cout << ans << endl;
		else
			cout << "Loowater is doomed!" << endl;
	}

	return 0;
}