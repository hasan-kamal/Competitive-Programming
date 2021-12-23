#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int absol(int x){
	return x >= 0 ? x : -1 * x;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	string s;
	while(t--){
		cin >> n;
		cin >> s;
		
		bool can = true;
		for(int i = 0; i < n - 1 - i; i++){
			int t = absol(s[i] - s[n - 1 - i]);
			if(t != 2 && t != 0){
				can = false;
				break;
			}
		} 

		cout << (can ? "YES" : "NO") << endl;
	}	

	return 0;
}