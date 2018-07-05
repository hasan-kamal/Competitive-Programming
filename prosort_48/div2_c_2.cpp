/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

void disp(vpii &t){
	cout<<endl;
	for(pii &p : t)
		cout<<p.first<<" "<<p.second<<endl;
	cout<<endl;
}

struct lt{
	inline bool operator()(const pii &p1, const pii &p2){
		if(p1.first==p2.first)
			return p1.second<p2.second;
		return p1.first<p2.first;
	}
};

int main(){

	int t, n;
	cin>>t;

	while(t--){
		cin>>n;
		vpii t;
		int a, b;
		for(int i=0; i<n; i++){
			cin>>a>>b;
			t.push_back(pii(a, 1));
			t.push_back(pii(b+1, -1));
		}
		sort(t.begin(), t.end(), lt());
		//disp(t);
		int sum=0, max=-1;
		for(pii &p : t){
			sum+=p.second;
			if(sum>max)
				max = sum;
		}

		cout<<max<<endl;
	}	
	
	return 0;
}