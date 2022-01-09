#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define P 499
#define S 101

int main() {

	/* Sieve */
	vector<int> pf(P * S, 1);
	vector<int> is_prime(P * S, 1);
	is_prime[1] = 0;
	for (long long int i = 2; i < P * S; i++) {
		if (!is_prime[i]) continue;
		for (long long int j = i * i; j < P * S; j += i) {
			is_prime[j] = 0;
			pf[j] = i;
		}
	}
	for (long long int i = 2; i < P * S; i++) {
		if (is_prime[i]) pf[i] = i;
	}

	int T, M, t_num = 0;
	cin >> T;

	while (T--) {
		cin >> M;

		unordered_map<int, int> inp;
		int p, n;
		for (int i = 0; i < M; i++) {
			cin >> p >> n;
			inp[p] = n;
		}

		int ans = 0;
		for (int sum = P * S - 1; sum > 1; sum--) {
			unordered_map<int, int> factorization;
			int prod = sum;
			while (prod > 1) {
				int factor = pf[prod];
				prod /= factor;
				if (factorization.find(factor) == factorization.end())
					factorization[factor] = 0;
				factorization[factor] += 1;
			}

			bool enough_primes = true;
			for (auto it = factorization.begin(); it != factorization.end(); it++) {
				if (inp.find(it->first) == inp.end() || inp[it->first] < it->second) {
					enough_primes = false;
					break;
				}
			}
			if (!enough_primes)
				continue;


			int lhs = 0;
			for (auto it = inp.begin(); it != inp.end(); it++) {
				lhs += (it->second - factorization[it->first]) * (it->first);
			}


			if (lhs == sum) {
				ans = sum;
				break;
			}
		}


		cout << "Case #" << ++t_num << ": " << ans << endl;
	}

	return 0;
}