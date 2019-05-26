#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

typedef vector<int>					vi;
typedef vector<vi>					vvi;
typedef set<int>					si;
typedef vector<si>					vsi;
typedef unordered_map<int, char>	mic;
typedef vector<mic>			 		vmic;

void print_choice(vmic &choice, vi &a, int i, int K){
	if(i == 0){
		cout << a[0];
		return;
	}

	char op = choice[i][K];
	int prev = -1;
	if(op == '+')
		prev = K - a[i];
	else if(op == '-')
		prev = K + a[i];
	else if(op == '*')
		prev = K / a[i];
	else if(op == '/')
		prev = K * a[i];
	print_choice(choice, a, i - 1, prev);
	cout << op << a[i];
}

bool in_range(int v){
	return v >= -32000 && v <= 32000;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	vsi v;
	vi a;
	vmic choice;
	while(t--){
		cin >> n;
		a = vi(n);
		for(int i = 0; i < n; ++i)
			cin >> a[i];
		int k;
		cin >> k;
		v = vsi(n, si());
		v[0].insert(a[0]);
		choice = vmic(n, mic());
		for(int i = 1; i < n; i++){
			for(si::iterator it = v[i - 1].begin(); it != v[i - 1].end(); it++){
				if(in_range((*it) + a[i])){
					v[i].insert((*it) + a[i]); choice[i][(*it) + a[i]] = '+';
				}
				if(in_range((*it) - a[i])){
					v[i].insert((*it) - a[i]); choice[i][(*it) - a[i]] = '-';
				}
				if(in_range((*it) * a[i])){
					v[i].insert((*it) * a[i]); choice[i][(*it) * a[i]] = '*';
				}
				if(*it % a[i] == 0 && in_range((*it) / a[i])){
					v[i].insert((*it) / a[i]); choice[i][(*it) / a[i]] = '/';
				}
			}
		}

		if(v[n - 1].find(k) == v[n - 1].end()){
			cout << "NO EXPRESSION" << endl;
			continue;
		}

		print_choice(choice, a, n - 1, k);
		cout << "=" << k << endl;
	}

	return 0;
}