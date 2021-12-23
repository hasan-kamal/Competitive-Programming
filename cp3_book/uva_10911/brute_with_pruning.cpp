// this submission passes in around 1 sec

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define INF 1000000000.0
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vii locs;
vi is_assgn;

double dist(ii p1, ii p2){
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double f(int to_assgn, int num_students, int num_assgned){
	if(is_assgn[to_assgn]){
		return f(to_assgn + 1, num_students, num_assgned);
	}

	is_assgn[to_assgn] = 1;
	double min_ans = INF;
	for(int i = to_assgn + 1; i < num_students; i++){
		if(!is_assgn[i]){
			double ans = 0.0;
			ans += dist(locs[to_assgn], locs[i]);
			if(ans > min_ans)
				continue;
			is_assgn[i] = 1;
			if(num_assgned + 2 < num_students)
				ans += f(to_assgn + 1, num_students, num_assgned + 2);
			is_assgn[i] = 0;
			min_ans = min(min_ans, ans);
		}
	}
	is_assgn[to_assgn] = 0;
	return min_ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int t = 1;
	string name;
	do{
		cin >> n;
		if(!n)
			break;
		locs = vii(2 * n);
		for(int i = 0; i < 2 * n; i++)
			cin >> name >> locs[i].first >> locs[i].second;
		is_assgn = vi(2 * n, 0);
		// cout << "Case " << t << ": " << f(0, 2 * n, 0) << endl;
		printf("Case %d: %.2lf\n", t, f(0, 2 * n, 0));
		t++;
	}while(n);

	return 0;
}