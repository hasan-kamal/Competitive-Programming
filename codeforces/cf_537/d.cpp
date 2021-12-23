#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <map>
#define M 1000000007
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef map<int, int> mii;

string s;
mii c_to_id;
mii count;
vi keys;

int f(int c1, int c2){
	if(c1 == c2){
		if(count[c1] > s.length() / 2)
			return 0;
		else{
			mii copy = count;
			copy[c1] = count[c1] - s.length() / 2;
			return get(copy);
		}
	}else if(count[c1] + count[c2] < s.length() / 2){
		
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	keys = vi();
	c_to_id = mii();
	count = mii();
	int counter = 0;
	for(char ch : s){
		if(c_to_id.find(ch) == c_to_id.end()){
			c_to_id[ch] = counter;
			count[ch] = 0;
			keys.push_back(ch);
			counter++;
		}
		count[ch]++;
	}

	int q;
	cin >> q;

	int x, y;
	while(q--){
		cin >> x >> y;
		cout << f(s[x - 1], s[y - 1]) << endl;
	}

	return 0;
}