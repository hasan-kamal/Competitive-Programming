#include <iostream>
#include <vector>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int ans;
vi c;
vi a;
vi col;

void visit(int s){
	col[s] = 1;
	if(col[a[s]] == 1){
		// ans += c[s];
		// cout << s << endl;
		vi x;

		int i = a[s];
		int m = INT_MAX;
		while(i != s){
			if(c[i] < m)
				m = c[i];
			i = a[i];
		}
		if(c[s] < m)
			m = c[s];
		ans += m;

	}else if(col[a[s]] == 2){
		;
	}else{
		visit(a[s]);
	}

	col[s] = 2;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	ans = 0;

	c = vi(n);
	for(int i = 0; i < n; i++)
		cin >> c[i];

	a = vi(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}

	// vis = vi(n, 0);
	col = vi(n, 0);
	for(int i = 0; i < n;  i++){
		if(!col[i])
			visit(i);
	}

	cout << ans;

	return 0;
}