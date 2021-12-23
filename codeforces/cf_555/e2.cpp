#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;
typedef pair<int, int> ii;
typedef set<ii> sii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	sii b;
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		b.insert(make_pair(temp, i));
	}

	for(int i = 0; i < n; i++){
		sii::iterator b_ = b.lower_bound(make_pair(n - a[i], -1));
		if(b_ == b.end())
			b_ = b.begin();
		cout << (a[i] + (*b_).first) % n << " ";
		b.erase(*b_);
	}

	return 0;
}