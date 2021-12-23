#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef set<ii> sii;
typedef map<int, int> mii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int u, v;
	viii all = viii();
	mii id_to_a = mii();
	mii id_to_b = mii();
	for(int i = 0; i < n; i++){
		cin >> u >> v;
		id_to_a[i] = u;
		id_to_b[i] = v;
		all.push_back(make_pair(make_pair(u, i), 1));
		all.push_back(make_pair(make_pair(v, i), -1));
	}

	sort(all.begin(), all.end());

	vii a = vii();
	vii b = vii();
	for(iii el : all){
		if(el.second == 1)
			a.push_back(make_pair(el.first.first, el.first.second));
		else
			b.push_back(make_pair(el.first.first, el.first.second));
	}

	int num_matched = 0;
	sii matched = sii();
	int largest_unmatched_a_index = n - 1;
	int largest_unmatched_b_index = n - 1;
	long long int ans = 0;

	for(iii el : all){
		ii elem = make_pair(el.first.second, el.second);
		if(matched.find(elem) != matched.end()){
			continue;
		}

		if(el.second == 1){
			// is A value
			int best_matching_index = -1;
			for(int potential = largest_unmatched_b_index; potential >= 0; potential--){
				if(b[potential].second != el.first.second && matched.find(make_pair(b[potential].second, -1)) == matched.end()){
					best_matching_index = potential;
					break;
				}
			}
			if(best_matching_index > 0){
				matched.insert(make_pair(b[best_matching_index].second, -1));
				matched.insert(elem);
				ans += min(id_to_a[el.first.second], id_to_b[b[best_matching_index].second]);
				num_matched += 1;
			}
			
			int i = largest_unmatched_b_index;
			while(i >= 0 && matched.find(make_pair(b[i].second, -1)) != matched.end())
				i--;
			largest_unmatched_b_index = i;
		}else{
			// is B value
			int best_matching_index = -1;
			for(int potential = largest_unmatched_a_index; potential >= 0; potential--){
				if(a[potential].second != el.first.second && matched.find(make_pair(a[potential].second, 1)) == matched.end()){
					best_matching_index = potential;
					break;
				}
			}
			if(best_matching_index > 0){
				matched.insert(make_pair(a[best_matching_index].second, 1));
				matched.insert(elem);
				ans += min(id_to_b[el.first.second], id_to_a[a[best_matching_index].second]);
				num_matched += 1;
			}
			
			int i = largest_unmatched_a_index;
			while(i >= 0 && matched.find(make_pair(a[i].second, 1)) != matched.end())
				i--;
			largest_unmatched_a_index = i;
		}
	}

	if(num_matched < n){
		// one id left unmatched
		int unmatched_id = -1;
		for(int i = 0; i < n; i++){
			if(matched.find(make_pair(i, 1)) == matched.end()){
				unmatched_id = i;
				break;
			}
		}

		ans += min(id_to_a[unmatched_id], id_to_b[unmatched_id]);
	}

	long long int ans_1 = 0;
	for(int i = 0; i < n; i++)
		ans_1 += id_to_a[i];

	long long int ans_2 = 0;
	for(int i = 0; i < n; i++)
		ans_2 += id_to_b[i];

	ans = min(ans, ans_1);
	ans = min(ans, ans_2);

	cout << ans << endl;

	return 0;
}