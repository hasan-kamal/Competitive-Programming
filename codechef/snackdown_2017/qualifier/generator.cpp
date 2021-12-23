#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

#define T 100
#define N 10000
#define Q 10000
#define L 1000000000

int main(){

	srand(time(NULL));
	int t = rand()%T+1;
	cout<<t<<endl;
	while(t--){
		int n = rand()%N+1;
		int q = rand()%Q+1;

		cout<<n<<" "<<q<<endl;
		for(int i=0; i<n; i++)
			cout<<rand()%L+1<<" ";
		cout<<endl;

		for(int i=0; i<q; i++)
			cout<<rand()%Q+1<<endl;
	}
	return 0;
}