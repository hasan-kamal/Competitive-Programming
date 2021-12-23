/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct custom_compare{
	//return true if first argument should appear first than second argument after sort() is called
	inline bool operator() (const int& x, const int &y){
		return x>y;
	}
};

void disp_vector(vector<int> &x){
	for(auto e : x)
		cout<<e<<" ";
	cout<<endl;
}

int main(){

	vector<int> v;
	for(int i=0; i<10; i++)
		v.push_back(i*i);

	disp_vector(v);
	sort(v.begin(), v.end(), custom_compare());
	disp_vector(v);

	return 0;
}