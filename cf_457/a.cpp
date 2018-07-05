/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <set>
#define pb push_back
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool contains(int m){
	if(m == 0)
		return false;
	else if(m % 10 == 7)
		return true;
	else
		return contains(m / 10);
}

int lucky(int h, int m, int x){
	if(contains(h) || contains(m))
		return 0;

	int minutes = h * 60 + m;
	minutes -= x;
	if(minutes < 0)
		minutes = 24 * 60 + minutes;

	int h_ = minutes / 60;
	int m_ = minutes % 60;

	return 1 + lucky(h_, m_, x);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int x;
	cin >> x;

	int h, m;
	cin >> h >> m;

	cout << lucky(h, m, x);		

	return 0;
}