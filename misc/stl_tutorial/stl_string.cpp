/*

@author Hasan Kamal

*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void disp_vector(vector<int> &v){
	for(auto e : v)
		cout<<e<<" ";
	cout<<endl;
}

int main(){

	//reading input line-by-line
	string s;
	while(getline(cin, s))
		cout << s << endl;
	
	//reading from a istringstream
	string s = "1 2 3";
	istringstream is(s);

	vector<int> v;
	int temp;
	while(is>>temp)
		v.push_back(temp);
	disp_vector(v);

	//output to a ostringstream
	ostringstream os;
	for(int x : v)
		os<<x<<" ";
	os<<endl;
	cout<<os.str();

	//string and C-style strings
	string s2 = "hello";
	const char *p = s2.c_str();
	printf("%s\n", p);

	return 0;
}