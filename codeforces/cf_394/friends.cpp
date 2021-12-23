#include <iostream>
#include <vector>
using namespace std;

bool is_same_vector(vector<int>& x, vector<int>& y){
	if(x.size()!=y.size())
		return false;
	for(int i=0; i<x.size(); i++){
		if(x[i]!=y[i])
			return false;
	}
	return true;
}

void disp(vector<int>& x){
	for(int i=0; i<x.size(); i++)
		cout<<x[i]<<" ";
	cout<<endl;
}

int main(){
	
	int n, l;
	cin>>n>>l;

	vector<int> b(n);
	vector<int> t(n);

	int i;
	for(i=0; i<n; i++)
		cin>>b[i];

	for(i=0; i<n; i++)
		cin>>t[i];

	bool yes = false;
	for(i=0; i<=b[n-1]; i++){
		
		int j = 0;
		while(b[j]<i)
			j++;

		vector<int> x;
		int alpha = 0;
		x.push_back(b[j]-i);
		for(alpha = 1; alpha<n; alpha++){
			
			int addition = b[(j+1)%n] - b[(j)%n];
			if(addition<0)
				addition = l - b[(j)%n] + b[(j+1)%n];

			j++;

			x.push_back( x[x.size()-1] + addition );
		}

		// cout<<i<<"::";
		// disp(x);
		// cout<<endl;

		if(is_same_vector(x, t)){
			yes = true;
			break;
		}
	}

	for(i=b[n-1]+1; i<l; i++){
		vector<int> x;
		int alpha = 0;
		x.push_back(b[0] + l - i);
		for(alpha=1; alpha<n; alpha++){
			x.push_back(x[x.size()-1] + b[alpha]-b[alpha-1]);
		}

		// cout<<i<<"::";
		// disp(x);
		// cout<<endl;

		if(is_same_vector(x, t)){
			yes = true;
			break;
		}
	}

	if(yes==true)
		cout<<"YES";
	else
		cout<<"NO";

	return 0;
}