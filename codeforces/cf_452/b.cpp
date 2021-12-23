/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

bool check(vi &a, vi & val){
	int n = val.size();
	for(int i = 0; i < 31 * 2; i++){
		int okay = 1;
		for(int j = i; j < i + n; j++){
			if(a[j] != val[j - i]){
				okay = 0;
				break;
			}
		}
		if(okay)
			return true;
	}
	return false;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi val(n);
	for(int i = 0; i < n; i++)
		cin >> val[i];

	vi a = vi(31 * 3);

	vi thir_one = {0, 2, 4, 6, 7, 9, 11};
	vi thir = {3, 5, 8, 10};

	for(int i = 0; i < 3; i++){
		for(int p : thir_one)
			a[12 * i + p] = 31;
		for(int p : thir)
			a[12 * i + p] = 30;
	}

	a[1] = a[13] = a[25] = 28;
	
	if(check(a, val)){
		cout << "YES" << endl;
		return 0;
	}

	a[25] = 29;
	if(check(a, val)){
		cout << "YES" << endl;
		return 0;
	}

	a[25] = 28;
	a[13] = 29;
	if(check(a, val)){
		cout << "YES" << endl;
		return 0;
	}

	a[25] = 28;
	a[13] = 28;
	a[1] = 29;
	if(check(a, val)){
		cout << "YES" << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}