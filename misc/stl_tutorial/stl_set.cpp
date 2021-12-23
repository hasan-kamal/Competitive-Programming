/*

@author Hasan Kamal

*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

void disp_vector(vector<int> &v){
	for(auto x : v)
		cout<<x<<" ";
	cout<<endl;
}

int main(){

	//basic sets
	set<int> s;
	for(int i=0; i<=10; i++)
		s.insert(i);
	s.insert(5); //does nothing, 5 already exists
	for(int i=0; i<=10; i+=2)
		s.erase(i); //erase all even values

	//traversing a set, can only be done through iterators
	//as a set obviously does not have indexing features
	for(set<int>::iterator it = s.begin(); it!=s.end(); it++)
		cout<<*it<<" ";
	cout<<endl;

	//checking the presence of an
	//element in set
	if(s.find(42)!=s.end()){ //here we are using set::find and not global find algorithm
		//42 present in the set
	}else
		//42 not present in the set

	s.erase(5); //remove 5 from the set

	//to remove duplicates and get the sorted order
	vector<int> v1 = {3, 3, 2, 2, 1};
	set<int> s1(v1.begin(), v1.end());
	vector<int> v2(s1.begin(), s1.end()); //v2 sorted with duplicates removed
	disp_vector(v2);

	return 0;
}