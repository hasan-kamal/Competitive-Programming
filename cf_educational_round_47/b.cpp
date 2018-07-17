#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;

	int ones = 0;
	for(char ch : s){
		if(ch == '1')
			ones++;
	}

	int n = s.length();
	bool seen_two = false;
	int pre_ones = 0;
	int pre_zeros = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '2' && !seen_two){
			seen_two = true;

			while(pre_zeros > 0){
				cout << "0";
				pre_zeros--;
			}

			int pre_ones2 = pre_ones;
			while(pre_ones > 0){
				cout << "1";
				pre_ones--;
			}

			ones = ones - pre_ones2;
			while(ones > 0){
				cout << "1";
				ones--;
			}
		}

		if(seen_two){
			if(s[i] == '2' || s[i] == '0')
				cout << s[i];
		}

		if(!seen_two){
			if(s[i] == '0')
				pre_zeros++;
			else
				pre_ones++;
		}
	}

	if(!seen_two){
		while(pre_zeros > 0){
			cout << "0";
			pre_zeros--;
		}

		while(pre_ones > 0){
			cout << "1";
			pre_ones--;
		}

		return 0;
	}

	return 0;
}