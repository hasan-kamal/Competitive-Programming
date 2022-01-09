#include <iostream>
using namespace std;

int main(){

	string s;
	while(getline(cin, s)){
		int d, a, b, c;
		sscanf(s.c_str(), "%d %d %d %d", &d, &a, &b, &c);
		if((d | a | b | c) == 0)
			break;
		int marks = 80 + (a <= d ? d - a : d + 40 - a) + 40 + (b >= a ? b - a : b + 40 - a) + (b >= c ? b - c : b + 40 - c);
		printf("%d\n", marks * 9);
	}

	return 0;
}