#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef multiset<int> 		si;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	bool odd = false;
	bool even = false;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] % 2 == 0)
			even = true;
		else
			odd = true;
	}

	
	if(even && odd){
		sort(a.begin(), a.end());
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		return 0;
	}

	for(int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}