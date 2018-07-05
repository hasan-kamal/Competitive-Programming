/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool okay(vvi &a, int n, int m, int i, int j){
	if(a[i][j] == INT_MAX)
		return true;
	int num_around = 0;
	for(int k = j - 1; k <= j + 1; k++){
		if(a[i - 1][k] == INT_MAX)
			num_around++;
		if(a[i + 1][k] == INT_MAX)
			num_around++;
	}
	if(a[i][j - 1] == INT_MAX)
		num_around++;
	if(a[i][j + 1] == INT_MAX)
		num_around++;
	return num_around == a[i][j];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vvi a(n + 2, vi(m + 2, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char ch;
			cin >> ch;
			if(ch == '.')
				a[i][j] = 0;
			else if(ch == '*')
				a[i][j] = INT_MAX;
			else
				a[i][j] = ch - '0';
		}
	}

	bool valid = true;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(!okay(a, n, m, i, j)){
				valid = false;
				break;
			}
		}
	}

	if(valid)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}