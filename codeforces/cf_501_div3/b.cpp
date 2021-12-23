#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef vector<int> vi;

vi a;
bool possible;

int f(string &s, string &t, int hi){
	if(hi == 0){
		if(s[0] == t[0])
			return 0;
		else{
			possible = false;
			return 0;
		}
	}

	if(s[hi] == t[hi])
		return f(s, t, hi - 1);
	else{
		// need to make a swap
		int loc = -1;
		for(int i = hi - 1; i >= 0; i--){
			if(s[i] == t[hi]){
				loc = i;
				break;
			}
		}
		if(loc == -1){
			possible = false;
			return 0;
		}

		for(int i = loc; i < hi; i++){
			a.pb(i);
			char temp = s[i + 1];
			s[i + 1] = s[i];
			s[i] = temp;
		}

		return 1 + f(s, t, hi - 1);
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s, t;
	cin >> s;
	cin >> t;

	a = vi();
	possible = true;
	int ans = f(s, t, n - 1);
	if(!possible){
		cout << -1;
		return 0;
	}

	cout << a.size() << endl;
	for(int x : a)
		cout << x + 1 << " ";

	return 0;
}