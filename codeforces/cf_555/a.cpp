#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int f_(int n){
	n++;
	while(n % 10 == 0)
		n /= 10;
	return n;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	set<int> v;
	v.insert(n);

	int f = f_(n);
	while(v.find(f) == v.end()){
		v.insert(f);
		f = f_(f);
	}

	cout << v.size();

	return 0;
}