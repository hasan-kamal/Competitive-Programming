/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a = vi(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	int constant_start = -1;
	int decrease_start = -1;

	for(int i = 1; i < n; i++){
		if(a[i + 1] <= a[i]){
			constant_start = i + 1;
			break;
		}
	}

	for(int i = 1; i < n; i++){
		if(a[i + 1] < a[i]){
			decrease_start = i + 1;
			break;
		}
	}

	bool is_uni;
		
	if(constant_start != -1 && decrease_start != -1){

		is_uni = true;
		int val = a[constant_start];
		for(int i = constant_start; i < decrease_start; i++){
			if(a[i] != val){
				is_uni = false;
				break;
			}
		}

		for(int i = decrease_start; i < n; i++){
			if(a[i + 1] >= a[i]){
				is_uni = false;
				break;
			}
		}

	}else if(constant_start == -1){

		//increasing strictly
		is_uni = true;

	}else{

		//decrease_start == -1
		//no decrease found
		is_uni = true;
		int val = a[constant_start];
		for(int i = constant_start; i <= n; i++){
			if(a[i] != val){
				is_uni = false;
				break;
			}
		}

	}

	if(is_uni)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}