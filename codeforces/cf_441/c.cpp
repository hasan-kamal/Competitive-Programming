/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int sum_digits(int num){
	int sum = 0;
	while(num > 0){
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

int main(){

	int n;
	cin >> n;

	vi ans = vi();
	for(int sum_dig = 1; sum_dig <= 100; sum_dig++){
		if(sum_digits(n - sum_dig) == sum_dig){
			ans.push_back(n - sum_dig);
		}
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(int a : ans)
		cout << a << " ";

	return 0;
}