#include <iostream>
#include <vector>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

typedef vector<int> vi;
typedef vector<vi> vvi;


int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> m >> m;

	vvc a = vvc(n, vc(m));
	for(int i = 0; i < n){
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	}

	vvi left = vvi(n, vi(m, 0));
	vvi right = vvi(n, vi(m, 0));
	vvi up = vvi(n, vi(m, 0));
	vvi down = vvi(n, vi(m, 0));

	for(int i = 0; i < n){
		for(int j = 0; j < m; j++){
			if(a[i][j] == '*'){
				
			}
		}
	}


	return 0;
}