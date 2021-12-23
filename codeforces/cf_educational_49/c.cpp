#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		vi a(n);
		int c = 0;
		map<int, int> m = map<int, int>();
		map<int, int> m2 = map<int, int>();
		vi count(n, 0);
		for(int i = 0; i < n; i++){
			cin >>  a[i];
			if(m.find(a[i]) == m.end()){
				m[a[i]] = c;
				m2[c] = a[i];
				count[c] = 1;
				c++;
			}else{
				count[m[a[i]]]++;
			}
		}

		vector< pair<int, int > > v = vector< pair<int, int > >();
		for(int i = 0; i < c; i++){
			if(count[i] >= 2){
				v.push_back(make_pair(m2[i], count[i]));
			}
		}

		sort(v.begin(), v.end());

		// for(auto x : v)
		// 	cout << x.first << " " << x.second << endl;
		// cout << endl << endl;

		double mina = LONG_MAX;
		ll besta, bestb;

		n = v.size();
		for(int i = 0; i < n; i++){
			if(v[i].second >= 4){
				double t = 4 * ((ll)v[i].first + v[i].first) * ((ll)v[i].first + v[i].first) / ((double) (ll)(v[i].first * v[i].first));
				if(t < mina){
					mina = t;
					bestb = besta = v[i].first;
				}
			}else{
				// can pick only two of these

				if(i - 1 >= 0){
					double t = 4 * ((ll)v[i].first + v[i - 1].first) * ((ll)v[i].first + v[i - 1].first) / ((double) (ll)(v[i].first * v[i - 1].first));
					if(t < mina){
						mina = t;
						bestb = v[i].first;
						besta = v[i - 1].first;
					}
				}

				if(i + 1 < n){
					double t = 4 * ((ll)v[i].first + v[i + 1].first) * ((ll)v[i].first + v[i + 1].first) / ((double) (ll)(v[i].first * v[i + 1].first));
					if(t < mina){
						mina = t;
						bestb = v[i].first;
						besta = v[i + 1].first;
					}
				}

			}
		}

		cout << besta << " " << besta << " ";
		cout << bestb << " " << bestb << endl;
	}

	return 0;
}