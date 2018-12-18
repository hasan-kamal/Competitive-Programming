#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#define M 1000000007
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<int, int> mii;
typedef long long int ll;
typedef set<int> si;

int num_elem_between(si &s, int low, int high){
	// return number of x s.t. low < x < hi; x in s
	int ans = 0;
	for(si::iterator it = s.begin(); it != s.end(); it++){
		if(*it > low && *it < high){
			ans++;
			return ans;
		}
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vii queries = vii(n);
	vi integers = vi();
	string t;
	int p;
	for(int i = 0; i < n; i++){
		cin >> t;
		cin >> p;
		if(t.compare("ADD") == 0){
			queries[i].first = 0;
			integers.push_back(p);
		}else if(t.compare("ACCEPT") == 0){
			queries[i].first = 1;
		}
		queries[i].second = p;
	}

	sort(integers.begin(), integers.end());
	mii val_to_id = mii();

	int i_size = integers.size();
	for(int i = 0; i < i_size; i++){
		val_to_id[integers[i]] = i + 1;
	}

	for(int i = 0; i < n; i++){
		queries[i].second = val_to_id[queries[i].second];
	}

	// now each value is between [1, n] where n <= 3.6 * 10^5
	ll ans = 1;
	int i = 0;
	while(i < n){

		if(queries[i].first == 1){ // first query can't be accept since book is empty righ now
			ans = 0;
			break;
		}

		ll this_ans = 0;
		// mii id_to_cid = mii();
		// process all add requests before first accept comes
		si vals;
		while(i < n && queries[i].first == 0){
			// id_to_cid[queries[i].second] = this_ans;
			this_ans++;
			vals.insert(queries[i].second);
			i++;
		}
		// vi vals = vi(this_ans, 0);

		// no accepts came
		if(i == n){
			ans = (ans * (this_ans + 1)) % M;
			break;
		}

		// first accept query comes for this piece
		ans = (2 * ans) % M;
		// cout << i << " " << ans << " " << this_ans << endl;
		// vals[]
		int size = this_ans;
		int max_accept = -1;
		int min_accept = 1000000000;
		int num_accept = 0;
		while(i < n && size > 0){
			if(queries[i].first == 1){
				size--;
				num_accept++;
				vals.erase(queries[i].second);
				if(num_accept > 1 && (num_elem_between(vals, max_accept, queries[i].second) > 0 || num_elem_between(vals, min_accept, queries[i].second) > 0)){
					ans = 0;
					// cout << i << " " << ans << endl;
					i = n;
					break;
				}
				min_accept = min(min_accept, queries[i].second);
				max_accept = max(max_accept, queries[i].second);
			}else{
				// add query
				// vals[id_to_cid[queries[i].]]
				vals.insert(queries[i].second);
				if(min_accept < queries[i].second && queries[i].second < max_accept){
					ans = (2 * ans) % M;
				}
				size++;
			}
			if(size == 0){
				break;
			}
			i++;
		}

		i++;
	}

	cout << ans;

	return 0;
}