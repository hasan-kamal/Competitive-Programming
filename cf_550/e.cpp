#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

void disp(int x){
	cout << (char)('a' + x);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	string s, t;
	cin >> s >> t;

	vi a(k);
	vi b(k);
	for(int i = 0; i < k; i++){
		a[i] = s[i] - 'a';
		b[i] = t[i] - 'a';
	}

	vi c(k);
	int carry = 0;
	for(int i = k - 1; i >= 0; i--){
		c[i] = (a[i] + b[i] + carry) % 26;
		carry = (a[i] + b[i] + carry) / 26;
	}

	for(int i = 0; i < k; i++){
		if(c[i] % 2 == 0)
			c[i] /= 2;
		else{
			c[i] = c[i] / 2;
			c[i + 1] += 13;
		}
	}

	for(int i = 0; i < k; i++){
		disp(c[i]);
	}


	return 0;
}