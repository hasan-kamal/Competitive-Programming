#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <map>
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
typedef set<int> 			si;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int b, c;
	map<int, int> count_map;
	set<int> count_set;
	for(int i = 0; i < m; i++){
		cin >> b >> c;
		if(count_map.find(c) == count_map.end())
			count_map[c] = 0;
		count_map[c] += b;
		count_set.insert(c);
	}

	for(int i = 0; i < n; i++){
		if(count_set.empty())
			break;
		int largest = *count_set.rbegin();
		if(a[i] < largest){
			a[i] = largest;
			count_map[largest]--;
			if(count_map[largest] <= 0){
				count_set.erase(largest);
			}
		}
	}

	ll ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i];
	cout << ans;
	return 0;
}