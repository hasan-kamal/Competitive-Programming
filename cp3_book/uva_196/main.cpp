#include <vector>
#include <iostream>
#include <map>
#include <cstring>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef vector<vvi>		vvvi;
typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef vector<vvi>		vvvi;
typedef map<int, int> 	mii;

int convert(string s, int m){
	int n_start = -1;
	for(int i = 0; i < (int)s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9'){
			n_start = i;
			break;
		}
	}
	int row = atoi(s.substr(n_start, s.length() - n_start).c_str());
	string c = s.substr(0, n_start);
	int col = 0;
	reverse(c.begin(), c.end());
	int p = 1;
	for(int i = 0; i < (int)c.length(); i++){
		col += (c[i] - 'A' + 1) * (p);
		p *= 26;
	}
	int index = (row - 1) * m + col - 1;
	// cout << s << " ---> " << index << endl;
	return index;
}

vvvi a;
mii leaf;
vvi ans;

void compute(int s, int m){
	int i = s / m;
	int j = s % m;

	if(ans[i][j] != INT_MIN)
		return;

	if(leaf[s]){
		ans[i][j] = a[i][j][0];
		return;
	}

	ans[i][j] = 0;
	// cout << "s-> ";
	for(int k = 0; k < (int)a[i][j].size(); k++){
		compute(a[i][j][k], m);
		// cout << a[i][j][k] << " ";
		ans[i][j] += ans[a[i][j][k] / m][a[i][j][k] % m];
	}
	// cout << endl;
}

int main(){

	int t;
	cin >> t;

	
	int n, m;
	while(t--){
		cin >> m >> n;

		a = vvvi(n, vvi(m, vi()));
		leaf = mii();
		string s;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> s;
				if(s[0] != '='){
					a[i][j].push_back(atoi(s.c_str()));
					leaf[i * m + j] = 1;
					continue;
				}
				leaf[i * m + j] = 0;
				int i_ = 1, j_ = 1;
				while(j_ < (int)s.length()){
					if(j_ != (int)s.length() - 1 && s[j_] != '+'){
						j_++;
						continue;
					}
					if(j_ == (int)s.length() - 1){
						a[i][j].push_back(convert(s.substr(i_, j_ - i_ + 1), m));
						j_++;	
						continue;
					}
					a[i][j].push_back(convert(s.substr(i_, j_ - i_), m));
					i_ = j_ + 1;
					j_ = i_;
				}

				// debug
				// cout << i * m + j << "(" << s << ")" << " -> ";
				// for(int ind = 0; ind < (int)a[i][j].size(); ind++)
				// 	cout << a[i][j][ind] << " ";
				// cout << endl;
			}
		}

		ans = vvi(n, vi(m, INT_MIN));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(ans[i][j] == INT_MIN)
					compute(i * m + j, m);
			}
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << ans[i][j];
				if(j < m - 1)
					cout << " ";
			}
			cout << endl;
		}
	}

	return 0;
}