/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, ans=0;
	cin>>n;

	string str;
	for(int i=0; i<n; i++){
		cin>>str;
		if(str.compare("Tetrahedron")==0)
			ans+=4;
		else if(str.compare("Cube")==0)
			ans+=6;
		else if(str.compare("Octahedron")==0)
			ans+=8;
		else if(str.compare("Dodecahedron")==0)
			ans+=12;
		else if(str.compare("Icosahedron")==0)
			ans+=20;
	}

	cout<<ans;

	return 0;
}