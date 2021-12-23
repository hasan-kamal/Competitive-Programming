/*

@author Hasan Kamal

*/

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void disp_map(map<int, int> &m){
	// vector<pair<int, int> > v(m.begin(), m.end());
	// for(pair<int, int> x : v)
	// 	cout<<"node "<<x.first<<" at distance "<<x.second<<endl;
	for(map<int, int>::iterator it = m.begin(); it!=m.end(); it++)
		cout<<"node "<<it->first<<" at distance "<<it->second<<endl; 
}

void disp_vector(vector< pair<string, int> > &v){
	for(auto x : v)
		cout<<x.first<<" "<<x.second<<endl;
}

int main(){

	map<string, int> m;
	m["hasan"] = 5;
	m["kamal"] = 10;
	cout<<m["hasan"]<<" "<<m["kamal"]<<endl;

	//map to vector
	//you get a sorted vector because map is sorted anyways
	vector< pair<string, int> > v(m.begin(), m.end());
	disp_vector(v);

	return 0;
}