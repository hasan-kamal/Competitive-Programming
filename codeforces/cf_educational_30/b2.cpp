/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	int n;
	cin >> n;

	string s;
	cin >> s;

	const int N = 2e5 + 1;
	const int OFFSET = 2e5;
	vi min_index = vi(OFFSET + N, INT_MAX);
	vi max_index = vi(OFFSET + N, -1);

	int counter = 0, min_counter = 0, max_counter = 0;
	min_index[OFFSET + counter] = min(min_index[OFFSET + counter], -1);
	max_index[OFFSET + counter] = max(max_index[OFFSET + counter], -1);
	
	for(int i = 0; i < n; i++){
		if(s[i] == '1')
			counter++;
		else
			counter--;

		min_index[OFFSET + counter] = min(min_index[OFFSET + counter], i);
		max_index[OFFSET + counter] = max(max_index[OFFSET + counter], i);

		if(counter < min_counter)
			min_counter = counter;
		if(counter > max_counter)
			max_counter = counter;
	}

	// min_index[OFFSET + counter] = min(min_index[OFFSET + counter], n);
	// max_index[OFFSET + counter] = max(max_index[OFFSET + counter], n);

	int ans = 0;
	for(int counter = min_counter; counter <= max_counter; counter++){
		if(min_index[OFFSET + counter] > max_index[OFFSET + counter])
			continue;
		int length = max_index[OFFSET + counter] - min_index[OFFSET + counter] + 1;
		if(length > ans)
			ans = length;
	}
	cout << ans - 1;

	return 0;
}