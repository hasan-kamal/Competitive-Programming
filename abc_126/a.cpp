#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int	ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;


	s[k - 1] = s[k - 1] + ('a' - 'A');
	cout << s;

	return 0;
}