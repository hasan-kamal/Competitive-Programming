#include <iostream>
#include <vector>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int min_i = 200, min_j = 200;
	int max_i = -1, max_j = -1;

	char ch;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> ch;
			if(ch == 'B'){
				if(i > max_i)
					max_i = i;
				if(j > max_j)
					max_j = j;
				if(i < min_i)
					min_i = i;
				if(j < min_j)
					min_j = j;
			}
		}
	}

	cout << 1 + (max_i + min_i) / 2 << " ";
	cout << 1 + (max_j + min_j) / 2;

	return 0;
}