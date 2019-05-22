#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;
	int counter = 0;
	int min_c = 0;
	for(char ch : s){
		if(ch == '-')
			counter--;
		else
			counter++;
		if(counter < min_c)
			min_c = counter;
	}
	cout << counter - min_c;

	return 0;
}