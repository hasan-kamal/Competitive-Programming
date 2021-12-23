#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> 	vi;
typedef vector<vi>		vvi;
typedef long long int	ll;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int a = atoi(s.substr(0, 2).c_str());
	int b = atoi(s.substr(2, 2).c_str());

	if(a >= 1 && a <= 12){
		if(b >= 1 && b <= 12){
			cout << "AMBIGUOUS" << endl;
		}else{
			cout << "MMYY" << endl;
		}
	}else{
		if(b >= 1 && b <= 12){
			cout << "YYMM" << endl;
		}else{
			cout << "NA" << endl;
		}
	}

	return 0;
}