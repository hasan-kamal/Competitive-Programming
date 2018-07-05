/*

@author hasankamal

*/

#include <iostream>
using namespace std;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int s, g;
	cin >> s >> g;

	if(s <= g){
		cout << "-1";
		return 0;
	}

	if(s % g == 0){
		cout << g << " " << s - g;
	}else{
		cout << "-1";
	}

	return 0;
}