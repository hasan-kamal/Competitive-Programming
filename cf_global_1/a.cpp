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

	int b, k;
	cin >> b >> k;

	vi a(k);
	for(int i = 0; i < k; i++)
		cin >> a[i];

	int sum = 0;
	int b_run = 1;
	for(int i = 0; i < k; i++){
		sum += (((a[k-i-1] % 10) * b_run)  % 10);
		b_run = (b_run * (b % 10)) % 10;
	}

	sum = sum % 10;
	if(sum % 2 == 0)
		cout << "even";
	else
		cout << "odd";

	return 0;
}