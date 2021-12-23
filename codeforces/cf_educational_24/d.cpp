/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> ii;
typedef set<ii> sii;

int main(){

	const int color_max = 1000000;

	int n, a;
	cin >> n >> a;
	
	vi c = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> c[i];

	int count_alice = 0;
	vi set_count = vi(color_max + 1, 0);
	sii set_colors = sii();
	int set_size = 0;

	//initiliaze initial possible set of colors
	for(int i = 1; i <= color_max; i++){
		if(i == a)
			continue;
		set_colors.insert(make_pair(0, i));
		set_size++;
	}
	set_count[a] = -1; //-1 denotes we cannot take this

	for(int i = 1; i <= n; i++){
		if(c[i] == a){
			//remove those colors from set with value count_alice
			if(set_size > 0){
				ii col_remove = *set_colors.begin();
				while(col_remove.first == count_alice){
					set_colors.erase(col_remove);
					set_count[col_remove.second] = -1; //cannot take this color from now on
					set_size--;
					if(set_size <= 0){
						break;
					}
					col_remove = *set_colors.begin();
				}
			}

			count_alice++;
		}else{

			if(set_count[c[i]] >= 0){

				ii old = make_pair(set_count[c[i]], c[i]);
				set_colors.erase(old);
				set_count[c[i]]++;
				ii new_p = make_pair(set_count[c[i]], c[i]);
				set_colors.insert(new_p);

			}

		}
	}

	if(set_size <= 0){
		cout << "-1";
	}else{
		cout << (*set_colors.begin()).second;
	}
	
	return 0;
}