#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int n;
vi sum;
vi next_;

int assign(int i){
	if(i > n - 1)
		return -1;
	if(sum[i] > 0){
		next_[i] = i;
		return i;
	}
	return next_[i] = assign(i + 1);
}

// returns smallest value greater than or equal to i that exists currently
int query(int i){
	if(next_[i] == -1)
		return -1;
	if(sum[next_[i]] > 0)
		return next_[i];
	return next_[i] = query(next_[i]);
}

// decreases value of i
// call this only if i was returned by query function above and i is not -1
int decrease(int i){
	sum[i]--;
	if(sum[i] <= 0){
		if(i == n - 1)
			next_[i] = -1;
		else
			next_[i] = next_[i + 1];
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	vi b(n);
	for(int i = 0; i < n; i++)
		cin >> b[i];

	sum = vi(n, 0);
	for(int i = 0; i < n; i++)
		sum[b[i]]++;

	next_ = vi(n, INT_MIN);
	for(int i = 0; i < n; i++)
		if(next_[i] == INT_MIN)
			assign(i);

	for(int i = 0; i < n; i++){
		int b_;
		if(n - a[i] < n){
			b_ = query(n - a[i]);
			if(b_ == -1)
				b_ = query(0);
		}else{
			b_ = query(0);
		}
		decrease(b_);

		cout << (a[i] + b_) % n << " ";
	}

	return 0;
}