/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef set<iii> siii;

vi parent, left_root, right_root;
vi cnt;

void show_q(siii &q){
	for(iii x : q)
		cout << "\t" << x.first << " " << x.second.first << " " << x.second.second << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(n);
	cnt = vi(n, 0);
	parent = vi(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i == 0){
			parent[i] = i;
		}else{
			if(a[i] == a[i - 1])
				parent[i] = parent[i - 1];
			else
				parent[i] = i;
		}
		cnt[parent[i]]++;
	}

	//assign left roots
	left_root = vi(n, -2);
	left_root[0] = -1;
	int last_root = 0;
	for(int i = 1; i < n; i++){
		if(cnt[i] > 0){
			left_root[i] = last_root;
			last_root = i;
		}
	}

	//assign right roots
	right_root = vi(n, -2);
	right_root[last_root] = -1;
	for(int i = last_root - 1; i >=0; i--){
		if(cnt[i] > 0){
			right_root[i] = last_root;
			last_root = i;
		}
	}

	siii q;
	for(int i = 0; i < n; i++){
		if(cnt[i] > 0)
			q.insert(make_pair(cnt[i], make_pair(-i, a[i])));
	}

	int ans = 0;
	while(!q.empty()){
		// show_q(q);
		iii max = *q.rbegin();
		q.erase(max);
		max.second.first = -max.second.first;
		// cout << max.second.second << endl;
		ans++;

		if(left_root[max.second.first] == -1 && right_root[max.second.first] == -1)
			continue;

		if(left_root[max.second.first] == -1){
			//leftmost segment being deleted
			left_root[right_root[max.second.first]] = -1;
		}else if(right_root[max.second.first] == -1){
			//rightmost segment being deleted
			right_root[left_root[max.second.first]] = -1;
		}else{

			int l_root = left_root[max.second.first];
			int r_root = right_root[max.second.first];
			if(a[l_root] != a[r_root]){
				left_root[r_root] = l_root;
				right_root[l_root] = r_root;
			}else{
				//coalescing needed

				q.erase(make_pair(cnt[r_root], make_pair(-r_root, a[r_root])));
				q.erase(make_pair(cnt[l_root], make_pair(-l_root, a[l_root])));

				cnt[l_root] = cnt[r_root] = cnt[l_root] + cnt[r_root];
				parent[r_root] = l_root;
				right_root[l_root] = right_root[r_root];
				left_root[r_root] = left_root[l_root];

				q.insert(make_pair(cnt[l_root], make_pair(-l_root, a[l_root])));
			}

		}
	}

	cout << ans;

	return 0;
}