#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;

vi tree;

void build_tree(int v, int start, int end, vii &counts){
	if(start == end){
		tree[v] = counts[start].second;
		return;
	}
	int mid = start + (end - start) / 2;
	build_tree(2 * v, start, mid, counts);
	build_tree(2 * v + 1, mid + 1, end, counts);
	tree[v] = max(tree[2 * v], tree[2 * v + 1]);
}

int query_tree(int v, int start, int end, int l, int r){
	cout << "::" << l << " " << r << endl;
	if(start == l && end == r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	if(r <= mid){
		return query_tree(2 * v, start, mid, l, r);
	}else if(mid < l){
		return query_tree(2 * v + 1, mid + 1, end, l, r);
	}else{
		int l_child = query_tree(2 * v, start, mid, l, mid);
		int r_child = query_tree(2 * v + 1, mid + 1, end, mid + 1, r);
		return max(l_child, r_child);
	}
}


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	int n;
	while(q--){
		cin >> n;

		vi a(n), f(n);
		for(int i = 0; i < n; i++)
			cin >> a[i] >> f[i];

		vi count(n + 1, 0);
		vi count_f(n + 1, 0);
		for(int i = 0; i < n; i++){
			count[a[i]]++;
			if(f[i])
				count_f[a[i]]++;
		}

		vii counts;
		for(int i = 1; i <= n; i++){
			if(count[i] > 0)
				counts.push_back(make_pair(count[i], count_f[i]));
		}
		sort(counts.rbegin(), counts.rend());

		vi count_z(n);
		for(int i = 0; i < n; i++)
			count_z[i] = counts[i].first;

		tree = vi(5 * n, 0);
		build_tree(1, 1, n, counts);

		ll sum = counts[0].first;
		ll sum_f = counts[0].second;
		ll last_val = counts[0].first;
		for(int i = 1; i < counts.size(); i++){
			if(min(last_val - 1, (ll) counts[i].first) <= 0)
				break;
			sum = sum + min(last_val - 1, (ll) counts[i].first);
			last_val = min(last_val - 1, (ll) counts[i].first);
			// sum_f = sum_f + min(last_val, (ll) counts[i].second);
			sum_f = sum_f + query_tree(1, 1, n, i + 1, max(i + 1, (int)(upper_bound(count_z.begin(), count_z.end(), last_val) - count_z.begin()) - 1));
		}
		cout << sum << " " << sum_f << endl;
	}		

	return 0;
}