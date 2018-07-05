/*

@author hasankamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi key(256, -1);
vi frozen(256, 0);

int f(int value, int k){
	if(key[value] != -1)
		return key[value];
	
	int x = value;
	while(x - 1 >= 0 && frozen[x - 1] == 0 && (value - (x - 1) + 1 <= k) && (  (key[x - 1] != -1 && value - key[x - 1] + 1 <= k)||(key[x - 1] == -1)  )){
		x--;
	}
		
	bool to_freeze = 0;
	if(value - x + 1 == k){
		to_freeze = 1;
	}

	for(int i = x; i <= value; i++){
		key[i] = x;
		frozen[i] = to_freeze;
	}

	return x;
}

// vi key(256, -1);

// int f(int value, int k){
// 	// if(key[value] != -1)
// 	// 	return key[value];
	
// 	int x = value;
// 	while(x - 1 >= 0 && (value - key[x - 1] + 1 <= k) )
// 		x--;
		
// 	for(int i = x; i <= value; i++){
// 		key[i] = x;
// 	}

// 	return x;
// }

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	// for(int i = 0; i < 256; i++)
	// 	key[i] = i;
	
	vi p(n);
	for(int i = 0; i < n; i++)
		cin >> p[i];

	vi ans(n);
	for(int i = 0; i < n; i++){
		ans[i] = f(p[i], k);
	}

	for(int i = 0; i < n; i++){
		cout << ans[i] << " ";
	}

	return 0;
}