#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// use ll !
	int n;
	cin >> n;

	set< pair<int, int> > even;
	set< pair<int, int> > odd;

	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		if(temp % 2 == 0)
			even.insert(make_pair(temp, i));
		else
			odd.insert(make_pair(temp, i));
	}

	set< pair<int, int> > larger;
	set< pair<int, int> > smaller;
	if(even.size() >= odd.size()){
		larger = even;
		smaller = odd;
	}else{
		larger = odd;
		smaller = even;
	}

	if(larger.size() == smaller.size()){
		cout << 0;
		return 0;
	}

	// try removing from larger first
	ll ans = 0;
	int rem = larger.size() - smaller.size() - 1;
	int count = 0;
	for(set< pair<int, int> >::iterator it = larger.begin(); it != larger.end(); it++){
		if(count >= rem)
			break;
		ans = ans + (*it).first;
		count++;
		if(count >= rem)
			break;
	}
	
	// try from smaller first
	ll ans2 = 0;
	rem = larger.size() - smaller.size();
	count = 0;
	for(set< pair<int, int> >::iterator it = larger.begin(); it != larger.end(); it++){
		if(count >= rem)
			break;
		ans2 = ans2 + (*it).first;
		count++;
		if(count >= rem)
			break;
	}

	cout << min(ans, ans2);

	return 0;
}