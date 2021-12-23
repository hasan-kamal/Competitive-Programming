#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long int ll;

void disp(vector<char> &a){
	for(int i = 0; i < a.size(); i++)
		cout << a[i];
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vi a(n);
	for(int  i = 0; i < n; i++)	
		cin >> a[i];

	int left = 1;
	int right = n - 1;
	int last_seq = a[0];
	vector<char> l;
	l.push_back('L');
	while(left <= right && max(a[left], a[right]) > last_seq){
		if( (a[left] < a[right] && a[left] > last_seq) || (a[left] >= a[right] && a[right] <= last_seq) ){
			// take left one
			l.push_back('L');
			last_seq = a[left];
			left++;
		}else{
			// take right one
			l.push_back('R');
			last_seq = a[right];
			right--;
		}
	}
	
	left = 0;
	right = n - 2;
	last_seq = a[n - 1];
	vector<char> r;
	r.push_back('R');
	while(left <= right && max(a[left], a[right]) > last_seq){
		if( (a[left] < a[right] && a[left] > last_seq) || (a[left] >= a[right] && a[right] <= last_seq) ){
			// take left one
			r.push_back('L');
			last_seq = a[left];
			left++;
		}else{
			// take right one
			r.push_back('R');
			last_seq = a[right];
			right--;
		}
	}

	if(l.size() > r.size()){
		cout << l.size() << endl;
		disp(l);
	}else{
		cout << r.size() << endl;
		disp(r);
	}

	return 0;
}