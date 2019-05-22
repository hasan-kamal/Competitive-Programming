#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;
	vector< set<int> > v(n, set<int>());

	while(m--){
		int s;
		cin >> s;

		set<int> k;
		int temp;
		while(s--){
			cin >> temp;
			temp--;
			k.insert(temp);
		}

		set<int> k_m;
		for(int i = 0; i < n; i++){
			if(k.find(i) == k.end())
				k_m.insert(i);
		}

		for(set<int>::iterator it=k.begin(); it!=k.end(); it++){
			for(set<int>::iterator it2=k_m.begin(); it2!=k_m.end(); it2++){
				if(v[*it2].find(*it) != v[*it2].end()){
					cout << "impossible";
					return 0;
				}
				v[*it].insert(*it2);
			}
		}
	}

	cout << "possible";

	return 0;
}