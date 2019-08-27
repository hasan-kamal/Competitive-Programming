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

bool interesting(int n){
	int sum = 0;
	while(n > 0){
		sum += (n % 10);
		n /= 10;
	}
	return sum % 4 == 0 ? true : false;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a;
	cin >> a;

	int n = a;
	while(!interesting(n))
		n++;
	cout << n;

	return 0;
}