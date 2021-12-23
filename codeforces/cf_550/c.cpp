#include <iostream>
#include <vector>
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

	vi a(n);
	vi count(200005, 0);
	int temp;
	int max_val = -1;
	int min_val = INT_MAX;
	for(int i = 0; i < n; i++){
		cin >> temp;
		count[temp]++;
		max_val = max(max_val, temp);
		min_val = min(min_val, temp);
	}


	set< int > inc;
	set< int > dec;
	for(int i = min_val; i <= max_val; i++){
		if(count[i] > 2){
			cout << "NO";
			return 0;
		}
		if(count[i] > 0){
			inc.insert(i);
			if(count[i] == 2){
				dec.insert(i);
			}
		}
	}

	cout << "YES" << endl;
	cout << inc.size() << endl;
	for(set<int>::iterator it = inc.begin(); it != inc.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	cout << dec.size() << endl;
	for(set<int>::reverse_iterator it = dec.rbegin(); it != dec.rend(); it++){
		cout << *it << " ";
	}
	cout << endl;



	return 0;
}