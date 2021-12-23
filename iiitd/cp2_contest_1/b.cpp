/*

@author hasankamal

*/

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

long long minimum(long long a, long long b){
	return a < b ? a : b;
}

long long absolute(long long x){
	return x < 0 ? -1 * x : x;
}

long long area(ii p1, ii p2, ii p3){
	long long x1 = p1.first;
	long long x2 = p2.first;
	long long x3 = p3.first;
	long long y1 = p1.second;
	long long y2 = p2.second;
	long long y3 = p3.second;
	return absolute( (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1) );
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vii points(n);
	for(int i = 0; i < n; i++){
		cin >> points[i].first;
		cin >> points[i].second;
	}

	long long min = LONG_MAX;
	// cout << min << endl;
	for(int i = 0; i < n; i++){
		min = minimum(min, area(points[i], points[(i + 1) % n], points[(i + 2) % n]));
	}
	cout << min;

	return 0;
}