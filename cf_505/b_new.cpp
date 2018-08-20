#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi sieve(45001, 1);
	vi first_pf(45001, -1);

	sieve[0] = sieve[1] = 0;
	for(int i = 2; i < 45000; i++){
		if(sieve[i] == 0)
			continue;
		first_pf[i] = i;
		for(int j = 2 * i; j < 45000; j += i){
			sieve[j] = 0;
			if(first_pf[j] == -1)
				first_pf[j] = i;
		}
	}

	map<int, int> m = map<int, int>();
	int num_p = 0;
	for(int i = 0; i < 45000; i++){
		if(sieve[i]){
			m[i] = num_p;
			num_p++;
		}
	}

	vi count = vi(32 * 150000 + 1, 0);

	int a, b;
	while(n--){
		cin >> a >> b;

		set<int> s = set<int>();
		while(a > 1){
			a /= first_pf[]
		}
	}
	

	return 0;
}