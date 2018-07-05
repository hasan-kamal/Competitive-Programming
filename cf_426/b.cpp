/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int k;
	cin >> k;

	string s;
	cin >> s;

	vi appeared_first = vi(26, -1);
	vi appeared_last = vi(26, -1);

	int len = s.length();
	for(int i = 0; i < len; i++){
		if(appeared_first[s[i] - 'A'] == -1){
			appeared_first[s[i] - 'A'] = i;
			appeared_last[s[i] - 'A'] = i;
		}else{
			appeared_last[s[i] - 'A'] = i;
		}
	}

	int l_max = -1, r_min = INT_MAX;
	vi count = vi(n + 1, 0);
	for(char c = 'A'; c <= 'Z'; c++){
		if(appeared_first[c - 'A'] == -1)
			continue;
		int l = appeared_first[c - 'A'];
		int r = appeared_last[c - 'A'];
		count[l]++;
		count[r + 1]--;
	}

	int sum = 0;
	int max_door = -1;
	for(int i = 0; i < n; i++){
		sum += count[i];
		if(sum > max_door)
			max_door = sum;
	}

	if(max_door > k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl; 

	return 0;
}