#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef set<iii> siii;
typedef priority_queue<iii>	pqiii;

// set<iii> s;
pqiii p;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vi a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	for(int i  = 0; i < n; i++){
		int count = 0;
		while(a[i] >= 0){
			// s.insert(make_pair(make_pair(a[i], count), i));
			// s.insert(make_pair(make_pair(a[i], count), i));
			p.push(make_pair(make_pair(-a[i], -count), -i));
			count++;
			if(a[i] == 0)
				break;
			a[i] /= 2;
		}
	}


	int ans = INT_MAX;
	int last_val = -1;
	int sum = 0, count = 0;
	while(!p.empty()){
		iii ab = p.top();
		p.pop();
		int val = -(ab).first.first;
		int unit = -(ab).first.second;
		if(val != last_val){
			sum = unit;
			count = 1;
			if(count >= k){
				ans = min(ans, sum);
			}
		}else{
			if(sum > ans)
				continue;
			sum += unit;
			count += 1;
			if(count >= k){
				ans = min(ans, sum);
			}
		}
		last_val = val;
	}

	cout << ans;
	
	return 0;
}