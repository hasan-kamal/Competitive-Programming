#include <iostream>
#include <string>
using namespace std;

int d(string &prev, string &next) {
	if (prev.length() < next.length()) return 0;
	int b = -1;
	for (int i = 0; i < next.length(); i++) {
		if (prev[i] != next[i]) {
			b = i;
			break;
		}
	}
	int old_length = next.length();

	if (b >= 0) {
		if (next[b] < prev[b]) {
			string app(prev.length() - next.length() + 1, '0');
			next += app;
			return prev.length() - old_length + 1;
		} else {
			string app(prev.length() - next.length() , '0');
			next += app;
			return prev.length() - old_length;
		}
	}

	int no_nine = -1;
	for (int j = prev.length() - 1; j > next.length() - 1; j--) {
		if (prev[j] != '9') {
			no_nine = j;
			break;
		}
	}
	
	if (no_nine >= 0) {
		for (int k = next.length(); k < no_nine; k++) next += prev[k];
		next += (prev[no_nine] + 1);
		string app(prev.length() - 1 - no_nine, '0');
		next += app;
		return prev.length() - old_length;
	}

	string app(prev.length() - next.length() + 1 , '0');
	next += app;
	return prev.length() - old_length + 1;
}

int main() {

	int T, N, t_num = 0;
	cin >> T;

	while (T--) {
		cin >> N;

		int ans = 0;
		string prev, num;
		for (int i = 0; i < N; i++) {
			cin >> num;
			if (i == 0) { prev =  num; continue; } 
			ans += d(prev, num);
			prev = num;
		}

		cout << "Case #" << ++t_num << ": " << ans << endl;
	}

	return 0;
}