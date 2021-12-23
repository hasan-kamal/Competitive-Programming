#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
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


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int q;
	cin >> q;

	ll sum_a = 0, sum_b = 0;
	si left, right;
	int c, a, b, median;
	while(q--){
		cin >> c;

		if(c == 1){
			cin >> a >> b;
			sum_b += b;

			if(left.size() == 0 && right.size() == 0){
				left.insert(a);
				median = a;
				continue;
			}

			if(left.size() < right.size()){
				if(a < *right.begin()){
					left.insert(a);
				}else{
					left.insert(*right.begin());
					right.erase(*right.begin());
					right.insert(a);
				}

				median = *left.rbegin();
			}else if(left.size() > right.size()){
				if(a > *left.rbegin()){
					right.insert(a);
				}else{
					right.insert(*left.rbegin());
					left.erase(*left.rbegin());
					left.insert(a);
				}
				median = *left.rbegin();
			}else{
				if(a < *right.begin()){
					left.insert(a);
					median = *left.rbegin();
				}else{
					right.insert(a);
					median = *right.begin();
				}
			}
			continue;
		}

		cout << median << " " << sum_a + sum_b << endl;		
	}

	return 0;
}