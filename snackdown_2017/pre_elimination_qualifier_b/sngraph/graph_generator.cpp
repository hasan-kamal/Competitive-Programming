/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int minimum(int x, int y){
	return x < y ? x : y;
}

int main(){

	int T, N, M;
	cin >> T >> N >> M;
	//cout << "T, N, M " << T << N << M << endl;

	srand(time(NULL));
	int t = (rand() % T) + 1;
	cout << t << endl;

	while(t--){
		int n = (rand() % N) + 1;
		int m = (rand() % M) + 1;
		m = minimum(m, n * (n-1) / 2);
		cout << n << " " << m << endl;

		vector< pair<int, int> > indices_in_matrix_free = vector < pair<int, int> >();

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i!=j)
					indices_in_matrix_free.push_back(make_pair(i, j));
			}
		}

		for(int i = 0; i < m; i++){
			pair<int, int> e = indices_in_matrix_free[rand()%indices_in_matrix_free.size()];
			cout << e.first + 1 << " " << e.second + 1 << endl;

			//remove e and (e.second, e.first) from free_indices_list
			pair<int, int> e2 = make_pair(e.second, e.first);
			vector< pair<int, int> > new_free_indices = vector< pair<int, int> >();
			for(pair<int, int> &p : indices_in_matrix_free){
				if(p != e && p!=e2)
					new_free_indices.push_back(p);
			}
			indices_in_matrix_free = new_free_indices;
		}
	}

	return 0;
}