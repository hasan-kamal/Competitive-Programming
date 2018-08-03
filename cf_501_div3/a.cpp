#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vi points = vi(m + 1, 0);
	int l, r;
	for(int i = 0; i < n; i++){
		cin >> l >> r;
		for(int j = l; j <= r; j++)
			points[j] = 1;
	}

	int ans = 0;
	for(int i = 1; i <= m; i++){
		if(points[i] == 0)
			ans++;
	}

	cout << ans << endl;
	for(int i = 1; i <= m; i++){
		if(points[i] == 0)
			cout << i << " ";
	}

	return 0;
}