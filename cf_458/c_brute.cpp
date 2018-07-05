/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int num_bits(int x){
	int count = 0;
	for(int i = 30; i >= 0; i--)
		if((x >> i) & 1)
			count++;
	return count;
}

int reduction(int n){
	if(n == 1)
		return 0;

	return 1 + reduction(num_bits(n));
}

int pow(int a, int b){
	int res = 1;
	while(b--)
		res *= a;
	return res;
}

int convert(string &s){
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '1')
			ans += pow(2, s.length() - 1 - i);
	}
	return ans;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = convert(s);
	// cout << n << endl;

	int k;
	cin >> k;

	int ans = 0;
	vi v;
	for(int i = 1; i <= n; i++){
		if(reduction(i) == k){
			ans++;
			v.push_back(i);
		}
	}

	cout << ans;

	// cout << ans << endl;
	// for(int x : v)
	// 	cout << x << " ";
	// cout << endl;

	return 0;
}