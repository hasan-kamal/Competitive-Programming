#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vi c = vi(n);
	for(int i = 0; i < n; i++)
		cin >> c[i];

	vi a = vi(m);
	for(int i = 0; i < m; i++)
		cin >> a[i];

	int ans = 0;

	int counter = 0;
	for(int i = 0; i < n; i++){
		if(a[counter] >= c[i]){
			ans++;
			counter++;
			if(counter >= m)
				break;
		}
	}
	cout << ans;

 return 0;
}