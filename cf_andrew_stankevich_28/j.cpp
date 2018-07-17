/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <cstdio>
#define BITSET_SIZE 1500
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){

	freopen("triatrip.in", "r", stdin);
	freopen("triatrip.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	char ch;
	vii edges = vii();
	vector< bitset<BITSET_SIZE> > bitsets = vector< bitset<BITSET_SIZE> >(n);
	char s[BITSET_SIZE];
	char grid[BITSET_SIZE][BITSET_SIZE];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> ch;
			grid[i][j] = ch;
			s[j] = '0';
			if(ch == '+'){
				edges.pb(make_pair(i, j));
				s[j] = '1';
			}
		}
		bitsets[i] = bitset<BITSET_SIZE>(string(s, s + n));
	}

	vector< bitset<BITSET_SIZE> > bitsets_rev = vector< bitset<BITSET_SIZE> >(n);
	for(int j = 0; j < n; j++){
		for(int i = 0; i < n; i++){
			if(grid[i][j] == '+')
				s[i] = '1';
			else
				s[i] = '0';
		}
		bitsets_rev[j] = bitset<BITSET_SIZE>(string(s, s + n));
	}

	long long int ans = 0;
	for(ii edge : edges){
		bitset<BITSET_SIZE> common = bitsets[edge.second] & bitsets_rev[edge.first];
		ans += common.count();
	}

	cout << ans / 3;

	return 0;
}