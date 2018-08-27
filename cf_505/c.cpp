#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.length();

	if(s[0] == s[n - 1]){
		int x = 1;
		int best = x;
		for(int i = 1; i < n; i++){
			if(s[i] == s[i - 1])
				x = 1;
			else
				x++;

			if(x > best)
				best = x;
		}
		cout << best;
		return 0;
	}

	bool okay = true;
	for(int i = 1; i < n; i++){
		if(s[i] == s[i - 1]){
			okay = false;
			break;
		}
	}

	if(okay){
		cout << n;
		return 0;
	}

	int i = 0;
	while(s[i + 1] != s[i])
		i++;

	int j = n - 1;
	while(s[j - 1] != s[j])
		j--;

	// cout << i + 1 + (n - j);
	int best = i + 1 + (n - j);

	int x = 1;
	// int best = x;
	for(int i = 1; i < n; i++){
		if(s[i] == s[i - 1])
			x = 1;
		else
			x++;

		if(x > best)
			best = x;
	}
	cout << best;

	return 0;
}