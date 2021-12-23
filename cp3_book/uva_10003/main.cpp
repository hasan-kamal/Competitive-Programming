#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> 		vi;
typedef vector<vi> 			vvi;
vi a;
vvi ans;

int f(int l, int r){
	if(ans[l][r] != INT_MAX)
		return ans[l][r];
	int len = r - l;
	int some_cut = false;
	for(int i = 0; i < (int)a.size(); i++){
		if(l < a[i] && a[i] < r){
			some_cut = true;
			ans[l][r] = min(ans[l][r], len + f(l, a[i]) + f(a[i], r));
		}
	}
	if(!some_cut)
		ans[l][r] = 0;
	return ans[l][r];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int l;
	while(cin >> l){
		if(!l)
			break;
		int n;
		cin >> n;

		a = vi(n, 0);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		ans = vvi(l + 1, vi(l + 1, INT_MAX));
		cout << "The minimum cutting is "<< f(0, l) << "." << endl;
	}

	return 0;
}