#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector<int>	 	vi;
typedef vector<vi>		vvi;
typedef set<int>	 	si;
typedef vector<si> 		vsi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vsi v(n);
	int temp;
	vvi a(n, vi(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			v[i].insert(a[i][j]);
		}
	}

	int max_ = -1, max_ind = -1;
	for(int i = 0; i < n; i++){
		if((int)v[i].size() > max_){
			max_ = v[i].size();
			max_ind = i;
		}
	}

	if(max_ > 1){

		vi ans(n, -1);
		int v = 0;
		for(int i = 0; i < n; i++){
			if(i == max_ind){
				continue;
			}
			v ^= a[i][0];
			ans[i] = 1;
		}
		int next_ind = 0;
		for(int i = 1; i < m; i++){
			if(a[max_ind][i] != a[max_ind][0]){
				next_ind = i;
				break;
			}
		}
		if(v != a[max_ind][next_ind]){
			v ^= a[max_ind][next_ind];
			ans[max_ind] = next_ind + 1;
		}else{
			v ^= a[max_ind][0];
			ans[max_ind] = 1;
		}
		cout << "TAK" << endl;
		for(int i = 0; i < n; i++)
			cout << ans[i] << " ";

		return 0;
	}

	int v_ = 0;
	for(int i = 0; i < n; i++)
		v_ ^= a[i][0];
	if(v_ != 0){
		cout << "TAK" << endl;
		for(int i = 0; i < n; i++)
			cout << 1 << " ";
		return 0;
	}

	cout << "NIE" << endl;

	return 0;
}