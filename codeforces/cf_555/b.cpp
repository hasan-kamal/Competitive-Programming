#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	vi f(11, -1);
	for(int i = 1; i <= 9; i++)
		cin >> f[i];

	int first_increase = -1;
	for(int i = 0; i < s.length(); i++){
		if(f[s[i] - '0'] > s[i] - '0'){
			first_increase = i;
			break;
		}
	}

	if(first_increase == -1){
		cout << s;
		return 0;
	}

	int first_decrease = s.length();
	for(int i = first_increase + 1; i < s.length(); i++){
		if(f[s[i] - '0'] < s[i] - '0'){
			first_decrease = i;
			break;
		}
	}

	for(int i = first_increase; i < first_decrease; i++)
		s[i] = '0' + f[s[i] - '0'];
	cout << s;

	return 0;
}