#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	while(n--){
		string s;
		cin >> s;

		int min_ = INT_MAX;
		int max_ = -1;
		int k = s.length();
		set<int> st;
		for(int i = 0; i < k; i++){
			min_ = min(min_, s[i] - '0');
			max_ = max(max_, s[i] - '0');
			st.insert(s[i] - '0');
		}

		if(max_ - min_ + 1 == k){
			bool okay = true;
			for(int i = min_; i <= max_; i++){
				if(st.find(i) == st.end()){
					okay = false;
					break;
				}
			}
			if(okay)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}	

	return 0;
}