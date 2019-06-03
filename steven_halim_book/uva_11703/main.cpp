#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <cmath>
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

#define M 1000000

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 1000005;
	vi ans(N, -1);
	ans[0] = 1;
	for(int i = 1; i < N; i++){
		int a = i - sqrt(i);
		int b = log(i);
		int c = i * sin(i) * sin(i);
		ans[i] = (ans[a] + ans[b]) % M;
		ans[i] = (ans[i] + ans[c]) % M;
	}

	int i;
	cin >> i;
	while(i != -1){
		cout << ans[i] << endl;
		cin >> i;
	}		

	return 0;
}