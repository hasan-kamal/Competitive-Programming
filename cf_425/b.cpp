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

bool is_good(char ch){
	int n = good.length();
	for(int i = 0; i < n; i++)
		if(good[i] == ch)
			return true;
	return false;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, good);

	string pattern;
	getline(cin, pattern);

	int n;
	cin >> n;
	int len = pattern.length();
	string query;
	getline(cin, query);
	while(n--){
		string query;
		getline(cin, query);

		bool is_valid = true;

		int query_len = query.length();
		//cout << "query_len " << query_len << endl;
		int i = 0;
		for(i = 0; (i < len) && (pattern[i] != '*'); i++){

			if(i >= query_len){
				is_valid = false;
				//cout << "here4" << endl;	
				break;
			}

			if(pattern[i] != '?'){
				if(pattern[i] != query[i]){
					is_valid = false;
					//cout << "here1" << endl;
					break;
				}
			}else{
				if(!is_good(query[i])){
					is_valid = false;
					//cout << "here2" << endl;
					break;
				}
			}
		}

		//cout << "here3 " << is_valid << endl;

		if(!is_valid){
			cout << "NO" << endl;
			continue;
		}

		if(i == len){
			if(query_len <= len){
				cout << "YES" << endl;
				continue;
			}else{
				cout << "NO" << endl;
				continue;
			}
		}

		int j = i;
		while( (j < query_len) && (!is_good(query[j])) )
			j++;

		i++;
		for(; i < len; i++, j++){
			if(j >= query_len){
				is_valid = false;
				break;
			}

			if(pattern[i] != '?'){
				if(pattern[i] != query[j]){
					is_valid = false;
					break;
				}
			}else{
				if(!is_good(query[j])){
					is_valid = false;
					break;
				}
			}
		}

		if(j < query_len){
			is_valid = false;
		}

		if(is_valid)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}				

	return 0;
}