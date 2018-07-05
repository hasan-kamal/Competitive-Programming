/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){

	int n, min, max;
	cin>>n>>min>>max;

	srand(time(NULL));
	while(n--){
		cout<<rand()%(max-min+1) + min<<endl;
	}

	return 0;
}