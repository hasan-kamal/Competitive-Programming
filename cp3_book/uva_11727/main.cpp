#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

	int t;
	cin >> t;

	vector<int> v(3);
	int i = 0;
	while(t--){
		cin >> v[0] >> v[1] >> v[2];
		sort(v.begin(), v.end());
		cout << "Case " << ++i << ": " << v[1] << endl;
	}

	return 0;
}