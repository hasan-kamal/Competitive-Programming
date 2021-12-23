#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vi a = vi(n);
	int l, r;

	ll com_sum = 0;
	ll un_sum = 0;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		a[i] = l - r;
		com_sum += r;
		un_sum += l;
	}

	if(com_sum > m){
		cout << -1;
		return 0;
	}

	sort(a.rbegin(), a.rend());
	ll extra = un_sum - m;

	int i = 0;
	while(extra > 0){
		extra -= a[i];
		i++;
	}

	cout << i;

	return 0;
}