/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n, k, len, temp;
	while(t--){

		cin >> n >> k;
		viii data = viii(n);
		vvi sets = vvi(n, vi(k + 1, 0));
		
		for(int i = 0; i < n; i++){
			cin >> len;
			data[i].first = len;
			data[i].second.first = INT_MIN; //max
			data[i].second.second = INT_MAX; //min
			for(int j = 0; j < len; j++){
				cin >> temp;
				sets[i][temp] = 1;
				if(temp > data[i].second.first)
					data[i].second.first = temp;
				if(temp < data[i].second.second)
					data[i].second.second = temp;
			}
		}

		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				
				if(data[i].first + data[j].first < k)
					continue;

				if(max(data[i].second.first, data[j].second.first) < k)
					continue;

				if(min(data[i].second.second, data[j].second.second) > 1)
					continue;

				ans++;
				for(int check = 1; check <= k; check++){
					if(sets[i][check] == 0 && sets[j][check] == 0){
						ans--;
						break;
					}
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}