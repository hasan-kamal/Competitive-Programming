// https://www.codechef.com/LTIME36/problems/ASTRING

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

string s;
int n;
void f(int i, int k){
	int m = i;
	for(int j = i + 1; j <= n - k; j++){
		if(s[j] < s[m])
			m = j;
	}
	cout << s[m];
	if(k - 1 > 0)
		f(m + 1, k - 1);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int k;
	while(t--){
		cin >> s;
		n = s.length();
		cin >> k;

		f(0, k);
		cout << endl;
	}

	return 0;
}