/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef set<int> si;

int main(){

	int n, m;
	cin >> n >> m;

	vi l = vi(m + 1);
	for(int i = 1; i <= m; i++)
		cin >> l[i];

	vi a = vi(n + 1, -1);

	vi values_used = vi(n + 1, 0);

	int current = l[1];
	for(int i = 2; i <= m; i++){

		int old = a[current];

		if(current < l[i])
			a[current] = l[i] - current;
		else
			a[current] = n - current + l[i]; //equality case handled here, 0 not allowed, n allowed

		if(old != -1 && old != a[current]){
			cout << "-1";
			return 0;
		}

		values_used[a[current]] = 1;

		for(int x = 1; x <= n; x++){
			if(current != x && a[current] == a[x]){
				cout << "-1";
				return 0;
			}
		}

		current = l[i];
	}

	si values_unused = si();
	for(int i = 1; i <= n; i++){
		if(values_used[i] == 0)
			values_unused.insert(i);
	}

	for(int i = 1; i <= n; i++){
		if(a[i] == -1){
			int t = *values_unused.begin(); 
			a[i] = t;
			values_unused.erase(t);
		}
	}

	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}