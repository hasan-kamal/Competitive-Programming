/*

@author Hasan Kamal

*/

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main(){

	ll n, q, c;
	scanf("%lld %lld %lld", &n, &q, &c);

	ll x, y, s;

	vvll window_s = vvll(102, vll(102, 0));
	vvll window_num = vvll(102, vll(102, 0));

	vvll s_matrix = vvll(102, vll(102, 0));
	vvll num_matrix = vvll(102, vll(102, 0));

	for(int i = 1; i <= n; i++){
		scanf("%lld %lld %lld", &x, &y, &s);
	
		s_matrix[x][y] += s;
		num_matrix[x][y] += 1;
	}

	for(ll x = 1; x <= 101; x++){
		for(ll y = 1; y <= 101; y++){
			ll more = 0;
			for(ll alpha = 1; alpha <= x; alpha++)
				more += s_matrix[alpha][y];
			window_s[x][y] = window_s[x][y - 1] + more;
		}
	}

	for(ll x = 1; x <= 101; x++){
		for(ll y = 1; y <= 101; y++){
			ll more = 0;
			for(ll alpha = 1; alpha <= x; alpha++)
				more += num_matrix[alpha][y];
			window_num[x][y] = window_num[x][y - 1] + more;
		}
	}

	ll t, x1, y1, x2, y2, ans, num_stars, s_sum;
	while(q--){
		scanf("%lld %lld %lld %lld %lld", &t, &x1, &y1, &x2, &y2);
		
		s_sum = 0;
		s_sum += (window_s[x2][y2] - window_s[x2][y1 - 1] - window_s[x1 - 1][y2] + window_s[x1 - 1][y1 - 1]);
		
		num_stars = 0;
		num_stars += (window_num[x2][y2] - window_num[x2][y1 - 1] - window_num[x1 - 1][y2] + window_num[x1 - 1][y1 - 1]);

		ans = 0;
		ans += ( (s_sum % (c + 1)) + num_stars*(t % (c + 1)) );

		printf("%lld\n", ans);
	}

	return 0;
}