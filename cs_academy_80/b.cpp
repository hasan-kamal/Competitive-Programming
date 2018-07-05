/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int count_arr[10];

int num_digits(vi &digits, int x){
	int ans = 0;
	while(x){
		digits.push_back(x % 10);
		x = x / 10;
		ans++;
	}
	reverse(digits.begin(), digits.end());
	return ans;
}

int get_largest(int b_digit){
	while(b_digit >= 0 && count_arr[b_digit] <= 0){
		b_digit--;
	}

	if(b_digit < 0)
		return -1;
	count_arr[b_digit]--;
	return b_digit;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	for(int i = 0; i < 10; i++)
		count_arr[i] = 0;

	vi bdigits, adigits;
	int num_bdigits = num_digits(bdigits, b);
	int num_adigits = num_digits(adigits, a);

	for(int z = 0; z < adigits.size(); z++){
		int adigit = adigits[z];
		count_arr[adigit]++;
	}

	// for(int adigit: adigits)
	// 	count_arr[adigit]++;

	if(num_adigits > num_bdigits){
		cout << "-1";
		return 0;
	}else if(num_bdigits > num_adigits){
		for(int x = 9; x >= 0; x--){
			while(count_arr[x] > 0){
				count_arr[x]--;
				cout << x;
			}
		}
		return 0;
	}

	vi ans;
	bool first_digit = true;
	for(int k = 0; k < bdigits.size(); k++){
		int bdigit = bdigits[k];
		int x = get_largest(bdigit);

		if(x == -1){
			cout << "-1";
			return 0;
		}
		if(x < bdigit){
			ans.push_back(x);
			for(int z = 0; z < ans.size(); z++){
				int y = ans[z];
				cout << y;
			}
			for(int x = 9; x >= 0; x--){
				while(count_arr[x] > 0){
					count_arr[x]--;
					cout << x;
				}
			}
			return 0;
		}
		if(first_digit && x == 0){
			cout << "-1";
			return 0;
		}
		first_digit = false;
		ans.push_back(x);
	}

	for(int z = 0; z < ans.size(); z++){
		int y = ans[z];
		cout << y;
	}

	return 0;
}