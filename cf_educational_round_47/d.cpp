#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef set<int> si;

int gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vi is_prime = vi(n + 1, 1);
	vi first_prime = vi(n + 1, 1);
	is_prime[0] = is_prime[1] = 0;
	for(long long i = 2; i <= n; i++){
		if(!is_prime[i])
			continue;
		first_prime[i] = i;
		for(long long j = i * i; j <= n; j += i){
			if(is_prime[j] = true)
				first_prime[j] = i;
			is_prime[j] = false;
		}
	}

	vi totient = vi(n + 1, 0);
	for(int i = 2; i <= n; i++){
		si facts = si();
		int val = i;
		while(val > 1){
			facts.insert(first_prime[val]);
			val /= first_prime[val];
		}

		totient[i] = i;
		for(si::iterator it = facts.begin(); it != facts.end(); it++){
			totient[i] /= (*it);
			totient[i] *= ((*it) - 1);
		}
	}

	long long sum = 0;
	for(int i = 1; i <= n; i++){
		sum += totient[i];
	}
	if(sum < m || m < n - 1){
		cout << "Impossible";
		return 0;
	}

	if((long long) m > (((long long)n) * (n - 1)) / 2){
		cout << "Impossible";
		return 0;	
	}

	if(n == 2){
		// m === 1 here
		cout << "Possible" << endl;
		cout << 1 << " " << 2 << endl;
		return 0;
	}

	if(m == n - 1){
		cout << "Possible" << endl;
		for(int i = 1; i < n; i++)
			cout << i << " " << i + 1 << endl;
		return 0;
	}

	cout << "Possible" << endl;
	vii edges = vii();
	for(int i = 1; i <= n; i++){
		if(i == n){
			edges.push_back(make_pair(n, 1));
			continue;
		}
		edges.push_back(make_pair(i, i + 1));
	}

	m -= n;
	for(int i = n; i > 1; i--){
		if(m <= 0)
			break;
		for(int j = 1; j < i; j++){
			if(j + 1 == i)
				continue; // already used
			if(i == n && j == 1)
				continue; // already used
			if(gcd(i, j) == 1){
				m--;
				edges.push_back(make_pair(j, i));
				if(m <= 0)
					break;
			}
		}
	}

	for(ii edge : edges)
		cout << edge.first << " " << edge.second << endl;

	return 0;
}