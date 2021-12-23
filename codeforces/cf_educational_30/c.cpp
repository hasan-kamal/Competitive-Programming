/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void display(vector<int> &v){
	for(int x : v)
		cout << x << " ";
	cout << endl;
}

int main(){

	int n, m, k;
	cin >> n >> m >> k;

	vvi a = vvi(n, vi(m));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];

	int cost = 0;
	int score = 0;
	for(int col = 0; col < m; col++){
		vi num_ones = vi(n, 0);
		int col_min_cost = INT_MAX;
		int col_best_score = 0;
		num_ones[0] = a[0][col];
		for(int row = 1; row < n; row++)
			num_ones[row] = num_ones[row - 1] + a[row][col];
		// cout << "col " << col << endl;
		// display(num_ones);
		for(int row = 0; row < n; row++){
			if(a[row][col] == 0)
				continue;
			//check this option
			int temp_cost;
			if(row - 1 >= 0)
				temp_cost = num_ones[row - 1];
			else
				temp_cost = 0;

			int temp_score;
			if(row - 1 >= 0)
				temp_score = num_ones[min(row + k - 1, n - 1)] - num_ones[row - 1];
			else
				temp_score = num_ones[min(row + k - 1, n - 1)];

			if(temp_score > col_best_score){
				col_best_score = temp_score;
				col_min_cost = temp_cost;
			}
		}

		if(col_best_score != 0){
			score += col_best_score;
			cost += col_min_cost;
		}

		// cout << col_best_score << "-" << endl;
		// cout << col_min_cost << "+" << endl;
	}

	cout << score << " " << cost;
	
	return 0;
}