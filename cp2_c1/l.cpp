/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	
	int n = s.length();
	vvi dp(26, vi(n + 1, INT_MAX));
	dp[s[n - 1] - 'a'][n - 1] = n - 1;
	for(int i = n - 2; i >= 0; i--){
		for(char ch = 'a'; ch <= 'z'; ch++){
			dp[ch - 'a'][i] = dp[ch - 'a'][i + 1];
		}
		dp[s[i] - 'a'][i] = i;
	}
	
	int q;
	cin >> q;

	bool cur = true;

	int length = 0;
	vi latest_cur_at_length(q);
	vi latest_l_at_length(q);
	latest_l_at_length[0] = -1;
	latest_cur_at_length[0] = true;

	int last_index = -1;
	vi ans_last_index(q);

	string command, letter;
	for(int it = 0; it < q; it++){
		cin >> command;
		
		if(cur == false){
			if(command.compare("push") == 0){
				cin >> letter;
				length++;
			}else{
				length--;
				cur = latest_cur_at_length[length];
				last_index = latest_l_at_length[length];
			}
		}else if(cur == true){
			if(command.compare("pop") == 0){
				length--;
				last_index = latest_l_at_length[length];
			}else{
				cin >> letter;
				length++;
				last_index = dp[letter[0] - 'a'][last_index + 1];
				if(last_index == INT_MAX){
					cur = false;
				}

			}
		}

		latest_cur_at_length[length] = cur;
		latest_l_at_length[length] = last_index;

		cout << (cur ? "YES" : "NO");
		cout << endl;

		// cout << "\t" << "i=" << it << endl;
		// cout << "\t" << command << " ";
		// if(command.compare("push") == 0)
		// 	cout << letter[0];
		// cout << endl;
		// cout << "\t" << "length=" << length << endl;
		// cout << "\t" << "last_index=" << last_index << endl;
		// cout << "\t" << "cur=" << cur << endl;
	}

	return 0;
}