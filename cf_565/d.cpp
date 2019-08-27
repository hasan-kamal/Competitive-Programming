#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <map>
using namespace std;

typedef vector<int>			vi;
typedef vector<vi>			vvi;
typedef vector<vvi>			vvvi;
typedef long long int 		ll;
typedef vector<ll>			vll;
typedef vector<vll>			vvll;
typedef vector<vvll>		vvvll;

typedef pair<int, int>		ii;
typedef vector<ii>			vii;
typedef set<int> 			si;
typedef map<int, int> 		mii;
typedef multiset<int> 		msi;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 2750131 + 1000;
	vi is_prime(N, 1);
	vi first_pf(N, 1);
	is_prime[0] = is_prime[1] = 0;
	first_pf[0] = 0;
	for(ll i = 2; i < N; i++){
		if(!is_prime[i])
			continue;
		first_pf[i] = i;
		for(ll j = i * i; j < N; j += i){
			is_prime[j] = 0;
			if(first_pf[j] == 1)
				first_pf[j] = i;
		}
	}

	mii num_to_prime;
	mii prime_to_num;
	int prime_count = 0;
	for(int i = 2; i < N; i++){
		if(is_prime[i]){
			prime_count++;
			num_to_prime[prime_count] = i;
			prime_to_num[i] = prime_count;
		}
	}
	// cout << "Haha" << endl;

	int n;
	cin >> n;

	msi b, b_np, b_p;
	int temp;
	for(int i = 0; i < 2 * n; i++){
		cin >> temp;
		b.insert(temp);
		if(prime_to_num.find(temp) == prime_to_num.end())
			b_np.insert(temp);
		else
			b_p.insert(temp);
	}

	for(msi::iterator it = b_p.begin(); it != b_p.end(); it++){
		cout << *it << " ";
	}
	// cout << endl;
	// for(msi::iterator it = b_np.begin(); it != b_np.end(); it++){
	// 	cout << *it << " ";
	// }
	// cout << endl;

	// cout << "Haha" << endl;

	msi a, a_p, a_np;
	msi t_l;
	for(msi::iterator it = b_np.begin(); it != b_np.end(); it++){
		// not prime
		int greatest_div = *it / first_pf[*it];
		if(b.find(greatest_div) != b.end()){
			b.erase(b.find(greatest_div));
			t_l.insert(greatest_div);
			a_np.insert(*it);
		}
	}

	// cout << "DFD" << endl;
	// for(msi::iterator it = b_p.begin(); it != b_p.end(); it++){
	// 	cout << *it << " ";
	// }
	// cout << "DFD" << endl;

	cout << endl;
	for(msi::iterator it = t_l.begin(); it != t_l.end(); it++){
		cout << *it << "AHA" << endl;
		if(b_p.find(*it) != b_p.end())
			b_p.erase(*it);
	}

	// for(msi::iterator it = b_p.begin(); it != b_p.end(); it++){
	// 	cout << *it << " ";
	// }
	// cout << "DFD" << endl;

	// cout << "Haha" << endl;

	for(msi::iterator it = b_p.begin(); it != b_p.end(); it++){
		// cout << *it << " dfd" << endl;
		int n_th_prime = num_to_prime[*it];
		if(b.find(n_th_prime) != b.end()){
			b.erase(b.find(n_th_prime));
			a_p.insert(*it);
		}
	}

	// cout << "Haha" << endl;

	for(msi::iterator it = a_np.begin(); it != a_np.end(); it++){
		cout << *it << " ";
	}
	for(msi::iterator it = a_p.begin(); it != a_p.end(); it++){
		cout << *it << " ";
	}

	return 0;
}