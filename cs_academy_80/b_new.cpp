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

int get_largest(int b_digit){
	while(b_digit >= 0 && count_arr[b_digit] <= 0){
		b_digit--;
	}

	if(b_digit < 0)
		return -1;
	return b_digit;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	for(int i = 0; i < 10; i++)
		count_arr[i] = 0;

	int num_digits = 0;
	while(a != 0){
		count_arr[a % 10]++;
		a = a / 10;
		num_digits++;
	}

	vi b_digits;
	int num_digits_b = 0;
	while(b != 0){
		b_digits.push_back(b % 10);
		b = b / 10;
		num_digits_b++;
	}

	if(num_digits > num_digits_b){
		cout << "-1";
		return 0;
	}else if(num_digits_b > num_digits){
		for(int x = 9; x >= 0; x--){
			while(count_arr[x] > 0)
				cout << x;
		}
		return 0;
	}

	reverse(b_digits.begin(), b_digits.end());

	vi ans;
	bool first = true;
	for(int bdigit : b_digits){
		int x = get_largest(bdigit);
		if(first && x == 0){
			cout << -1;
			return 0;
		}
		if(x == -1){
			cout << "-1";
			return 0;
		}
		ans.push_back(x);
		count_arr[x]--;
		first = false;
	}

	for(int y : ans)
		cout << y;

	return 0;
}