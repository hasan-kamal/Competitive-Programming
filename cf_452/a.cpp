/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int minimum(int x, int y){
	return x < y ? x : y;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int temp, x = 0, y = 0;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp == 1)
			x++;
		else
			y++;
	}

	int alpha;
	if(x > y)
		alpha = (x - minimum(x, y)) / 3;
	else
		alpha = 0;

	cout << minimum(x, y) + alpha;

	return 0;
}