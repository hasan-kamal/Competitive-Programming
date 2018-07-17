/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vii rect = vii(n);
	for(int i = 0; i < n; i++){
		cin >> rect[i].first >> rect[i].second;
		if(rect[i].first < rect[i].second){
			int temp = rect[i].first;
			rect[i].first = rect[i].second;
			rect[i].second = temp;
		}
	}

	int cur = rect[0].first;
	for(int i = 1; i < n; i++){
		if(rect[i].first <= cur){
			cur = rect[i].first;
		}else if(rect[i].second <= cur){
			cur = rect[i].second;
		}else{
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";

	return 0;
}