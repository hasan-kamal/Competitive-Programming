#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int sum1 = 0, sum2 = 0;	

	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		sum1 += temp;
	}

	for(int i = 0; i < n; i++){
		cin >> temp;
		sum2 += temp;
	}

	if(sum2 > sum1)
		cout << "No";
	else
		cout << "Yes";

	return 0;
}