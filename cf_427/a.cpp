/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;

	int first = 2 * t1 + s * v1;
	int sec = 2 * t2 + s * v2;

	if(first < sec)
		cout << "First" << endl;
	else if(sec < first)
		cout << "Second" << endl;
	else
		cout << "Friendship" << endl;

	return 0;
}