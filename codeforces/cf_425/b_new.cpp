/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;

string good;
vi a_good;

bool is_good(char ch){
	return a_good[ch - 'a'] == 1;
}

bool matches(string &pattern, int i1, int j1, string &query, int i2, int j2){
	if(j1 - i1 != j2 - i2)
		return false;

	int i = i1;
	int j = i2;
	for(; i <= j1; i++, j++){
		if(pattern[i] != '?'){
			if(pattern[i] != query[j]){
				return false;
			}
		}else{
			if(!is_good(query[j])){
				return false;
			}
		}
	}

	return true;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	a_good = vi(26, 0);
	cin >> good;
	for(char ch : good)
		a_good[ch - 'a'] = 1;

	string pattern;
	cin >> pattern;

	int n;
	cin >> n;
	int pattern_len = pattern.length();

	bool has_star = false;
	int asterisk_index = -1;
	for(int i = 0; i < pattern_len; i++){
		if(pattern[i] == '*'){
			has_star = true;
			asterisk_index = i;
			break;
		}
	}

	string query;
	
	while(n--){
		cin >> query;

		bool is_valid = true;
		int query_len = query.length();	

		if(!has_star){
			
			if(query_len != pattern_len){
				cout << "NO" << endl;
				continue;
			}

			is_valid = matches(pattern, 0, pattern_len - 1, query, 0, query_len - 1);

			if(!is_valid){
				cout << "NO" << endl;
				continue;
			}else{
				cout << "YES" << endl;
				continue;
			}

		}else{

			if(asterisk_index > query_len){
				cout << "NO" << endl;
				continue;
			}

			if(!matches(pattern, 0, asterisk_index - 1, query, 0, asterisk_index - 1)){
				cout << "NO" << endl;
				continue;
			}

			if(pattern_len - 1 - asterisk_index > query_len){
				cout << "NO" << endl;
				continue;
			}

			string suf_pattern = pattern.substr(asterisk_index + 1, pattern_len - 1 - asterisk_index);
			string suf_query = query.substr(query_len - suf_pattern.length(), suf_pattern.length());

			if(!matches(suf_pattern, 0, suf_pattern.length() - 1, suf_query, 0, suf_query.length() - 1)){
				cout << "NO" << endl;
				continue;
			}

			int i1 = asterisk_index;
			int i2 = query_len - 1 - suf_pattern.length();

			if(i1 - i2 > 1){
				cout << "NO" << endl;
				continue;
			}else if(i2 == i1 - 1){
				cout << "YES" << endl;
				continue;
			}else{
				
				for(int i = i1; i <= i2; i++){
					if(is_good(query[i])){
						is_valid = false;
						break;
					}
				}

				if(is_valid){
					cout << "YES" << endl;
					continue;
				}else{
					cout << "NO" << endl;
					continue;
				}

			}

		}
	}				

	return 0;
}