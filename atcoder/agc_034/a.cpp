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

void disp(si &a){
	for(si::iterator it = a.begin(); it != a.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	a--; b--; c--; d--;

	string s;
	cin >> s;

	vi pos(n, 0);
	pos[c] = 1;
	for(int i = c; i >= 0; i--){
		if(!pos[i])
			continue;

		// i has c possible
		if(i - 1 >= 0 && s[i - 1] == '.')
			pos[i - 1] = 1;
		if(i - 2 >= 0 && s[i - 2] == '.')
			pos[i - 2] = 1;

	}
	vi reachable_c = pos;

	if(!pos[a]){
		cout << "No";
		return 0;
	}

	pos = vi(n, 0);
	pos[d] = 1;
	for(int i = d; i >= 0; i--){
		if(!pos[i])
			continue;

		// i has d possible
		if(i - 1 >= 0 && s[i - 1] == '.')
			pos[i - 1] = 1;
		if(i - 2 >= 0 && s[i - 2] == '.')
			pos[i - 2] = 1;
	}

	if(!pos[b]){
		cout << "No";
		return 0;
	}

	if(c < d){
		cout << "Yes";
		return 0;
	}

	pos = vi(n, 0);
	pos[b] = 1;
	vi prev(n, -1);
	for(int i = b; i < n; i++){
		if(pos[i] == 0)
			continue;
		if(i + 1 < n && s[i + 1] == '.'){
			pos[i + 1] += pos[i];
			pos[i + 1] = min(pos[i + 1], 2);
			prev[i + 1] = i;
		}
		if(i + 2 < n && s[i + 2] == '.'){
			pos[i + 2] += pos[i];
			pos[i + 2] = min(pos[i + 2], 2);
			prev[i + 2] = i;
		}
	}

	// cout << "Haha" << endl;
	if(pos[d] >= 2){
		cout << "Yes";
		return 0;
	}

	si b_d;
	int p = d;
	while(p != -1){
		b_d.insert(p);
		p = prev[p];
	}

	pos = vi(n, 0);
	pos[a] = 1;
	prev = vi(n, -1);
	for(int i = a; i < n; i++){
		if(pos[i] == 0)
			continue;
		if(i + 1 < n && s[i + 1] == '.'){
			pos[i + 1] += pos[i];
			pos[i + 1] = min(pos[i + 1], 2);
			prev[i + 1] = i;
		}
		if(i + 2 < n && s[i + 2] == '.'){
			pos[i + 2] += pos[i];
			pos[i + 2] = min(pos[i + 2], 2);
			prev[i + 2] = i;
		}
	}
	vi reachable_a = pos;

	// cout << "Haha" << endl;
	si links;
	for(int alpha = b; alpha <= d; alpha++){
		if(reachable_a[alpha] > 0 && reachable_c[alpha] > 0){
			links.insert(alpha);
		}
	}

	// si a_c;
	// p = c;
	// while(p != -1){
	// 	a_c.insert(p);
	// 	p = prev[p];
	// }

	// disp(a_c);
	// disp(b_d);

	bool common_path = true;
	for(si::iterator it = links.begin(); it != links.end(); it++){
		if(b_d.find(*it) == b_d.end()){
			common_path = false;
			break;
		}
	}

	if(common_path)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}