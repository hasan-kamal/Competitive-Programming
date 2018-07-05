/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
#define M 1e5 + 2
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef set<ii> sii;
typedef vector<sii> vsii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, m;
	cin >> n >> k >> m;

	vi a = vi(M, 0);
	vsii col = vsii(M, sii());

	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		a[temp % m]++;
		col[temp % m].insert(make_pair(temp, i));
	}

	for(int i = 0; i < m; i++){
		if(a[i] >= k){
			cout << "Yes" << endl;
			for(sii::iterator it = col[i].begin(); it != col[i].end() && k > 0; it++, k--)
				cout << (*it).first << " ";
			return 0;
		}
	}

	cout << "No";

	return 0;
}