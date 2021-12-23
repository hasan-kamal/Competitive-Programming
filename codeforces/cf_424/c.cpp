/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, n;
	cin >> k >> n;

	vi a = vi(k + 1);
	for(int i = 1; i <= k; i++){
		cin >> a[i];
	}

	si b = si();
	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		b.insert(temp);
	}

	si possible_answers = si();
	int sum = 0;
	for(int i = 1; i <= k; i++){
		sum += a[i];
		possible_answers.insert(*b.begin() - sum);
	}

	int ans = 0;
	for(int x : possible_answers){
		
		si copy_b = si(b);
		int sm = x;
		for(int i = 1; i <= k; i++){
			sm += a[i];
			if(copy_b.find(sm) != copy_b.end())
				copy_b.erase(sm);
		}

		if(copy_b.size() == 0)
			ans++;
	}
	cout << ans;

	return 0;
}