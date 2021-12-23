#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	if(k < 25){
		cout << -1;
		return 0;
	}

	int alpha = -1;
	for(int i = 5; i <= k; i++)
		if(k % i == 0){
			alpha = i;
			break;
		}

	int beta = k / alpha;

	if(beta < 5){
		cout << -1;
		return 0;
	}

	vector<char> v;
	v.push_back('a');
	v.push_back('e');
	v.push_back('i');
	v.push_back('o');
	v.push_back('u');
	vector< vector<char> > a(alpha, vector<char>(beta));
	for(int j = 0; j < beta; j++){
		for(int i = 0; i < alpha; i++){
			a[i][j] = v[(i + j) % 5];
		}
	}

	for(int i = 0; i < alpha; i++){
		for(int j = 0; j < beta; j++){
			cout << a[i][j];
		}
		// cout << endl;
	}

	return 0;
}