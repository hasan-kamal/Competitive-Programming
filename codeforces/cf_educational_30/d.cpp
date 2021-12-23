/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef vector<int> vi;

vi make_seq(int s, int e){
	vi ans;
	for(int i = s; i <= e; i++)
		ans.pb(i);
	return ans;
}

vi get_valid_perm(int s, int e, int k, int indent = 0){
	// string sp = "";
	// for(int t = 0; t < indent; t++)
	// 	sp += "\t";

	// cout << sp << "entering " << s << ", " << e << " " << k << endl;

	if(k == 1)
		return make_seq(s, e);

	int n = e - s + 1;
	int k1;
	if(k >= 1 + ((n / 2) << 1)){
		k1 = ((n / 2) << 1) - 1;
	}else
		k1 = 1;

	vi lhs = get_valid_perm(e - n / 2 + 1, e, k1, indent + 1);
	vi rhs = get_valid_perm(s, e - n / 2, k - k1 - 1, indent + 1);
	vi ans = lhs;
	for(int r : rhs)
		ans.pb(r);

	// cout << sp << "exiting " << s << ", " << e << " " << k << endl;
	return ans;
}

int main(){

	int n, k;
	cin >> n >> k;

	if((k & 1) == 0 || k > (n << 1) - 1){
		cout << "-1";
		return 0;
	}

	if(n == 1){
		cout << "1";
		return 0;
	}

	vi perm = get_valid_perm(1, n, k);
	for(int v : perm)
		cout << v << " ";

	return 0;
}