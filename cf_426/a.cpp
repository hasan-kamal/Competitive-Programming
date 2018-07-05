/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;

char one = 'v';
char two = '<';
char three = '^';
char four = '>';

char get_clockwise(char st, int n){
	vc clock_wise = vc();
	clock_wise.pb(one);
	clock_wise.pb(two);
	clock_wise.pb(three);
	clock_wise.pb(four);
	int i = 0;
	if(st == one)
		i = 0;
	else if(st == two)
		i = 1;
	else if(st == three)
		i = 2;
	else
		i = 3;
	return clock_wise[(i + n) % 4];
}

char get_anticlockwise(char st, int n){
	vc anticlockwise = vc();
	anticlockwise.pb(one);
	anticlockwise.pb(four);
	anticlockwise.pb(three);
	anticlockwise.pb(two);
	int i = 0;
	if(st == one)
		i = 0;
	else if(st == four)
		i = 1;
	else if(st == three)
		i = 2;
	else
		i = 3;
	return anticlockwise[(i + n) % 4];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	getline(cin, s);
	
	char st = s[0];
	char end = s[2];
	
	int n;
	cin >> n;

	if((get_clockwise(st, n) == end) && (get_anticlockwise(st, n) != end))
		cout << "cw";
	else if((get_clockwise(st, n) != end) && (get_anticlockwise(st, n) == end))
		cout << "ccw";
	else
		cout << "undefined";

	return 0;
}