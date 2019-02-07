#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vi a(m + 1, 0);
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		a[temp]++;
	}

	
	// try from left
	int ans_left = 0;
	vi a_left = a;
	for(int i = 1; i + 2 <= m; i++){
		int count = min(min(a_left[i], a_left[i + 1]), a_left[i + 2]);
		// cout << i << " " << count << endl;
		// if(count > 0){
			ans_left += count;
		a_left[i] -= count;
		a_left[i + 1] -= count;
		a_left[i + 2] -= count;
	// }
	}

	for(int i = 1; i <= m; i++){
		ans_left += (a_left[i] / 3);
	}

	// try from right
	int ans_right = 0;
	vi a_right = a;
	for(int i = m; i - 2 >= 1; i--){
		int count = min(min(a_right[i], a_right[i - 1]), a_right[i - 2]);
		// if(count > 0){
		cout << i << " " << count << endl;
		ans_right += count;
		a_right[i] -= count;
		a_right[i - 1] -= count;
		a_right[i - 2] -= count;
		// }
	}

	for(int i = m; i >= 1; i--){
		ans_right += (a_right[i] / 3);
	}

	cout << max(ans_left, ans_right);


	return 0;
}