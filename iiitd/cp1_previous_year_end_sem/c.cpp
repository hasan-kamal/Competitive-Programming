/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

ll convert_seconds(string& s){
	ll hour = (s[0] - '0') * 10 + (s[1] - '0');
	ll minute = (s[3] - '0') * 10 + (s[4] - '0');
	ll second = (s[6] - '0') * 10 + (s[7] - '0');
	return hour * 60 * 60 + minute * 60 + second;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	while(t--){
		ll n;
		cin >> n;

		vll time = vll(n);

		string t;
		for(int i = 0; i < n; i++){
			cin >> t;
			time[i] = convert_seconds(t);
		}

		sort(t.begin(), t.end());

		priority_queue<ll> pq;

		int person_count = 0;
		for(int i = 0; i < n; i++){
			if(person_count == 0){
				pq.push(-1 * (time[i] + 15 * 60));
				person_count++;
				continue;
			}

			ll next_available = -1 * pq.top();
			//cout << time[i] << " " << next_available << endl;
			if(next_available <= (time[i] + 3 * 60 * 60 - 15 * 60 - 1)){
				//cout << i << " used " << endl;
				pq.pop();
				pq.push(-1 * (next_available + 15 * 60));
			}else{
				person_count++;
				pq.push(-1 * (time[i] + 15 * 60));
			}
		}

		cout << person_count << endl;
	}

	return 0;
}