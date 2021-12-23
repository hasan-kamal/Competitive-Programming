/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

vii points;
vi points_x_sort, points_y_sort;

int main(){

	ll n;
	cin>>n;

	points = vii(n);
	points_x_sort = vi(n);
	points_y_sort = vi(n);
	for(ll i=0; i<n; i++){
		cin>>points[i].first>>points[i].second;
		points_x_sort[i] = points[i].first;
		points_y_sort[i] = points[i].second;
	}

	sort(points.begin(), points.end());
	sort(points_x_sort.begin(), points_x_sort.end());
	sort(points_y_sort.begin(), points_y_sort.end());

	ll ans_x = 0;
	ll num_equal_vals = 1;
	for(ll i=1; i<n; i++){
		if(points_x_sort[i]==points_x_sort[i-1])
			num_equal_vals++;
		else{
			ans_x+=(num_equal_vals*(num_equal_vals-1)/2);
			num_equal_vals = 1;
		}
	}
	ans_x+=(num_equal_vals*(num_equal_vals-1)/2);

	ll ans_y = 0;
	num_equal_vals = 1;
	for(ll i=1; i<n; i++){
		if(points_y_sort[i]==points_y_sort[i-1])
			num_equal_vals++;
		else{
			ans_y+=(num_equal_vals*(num_equal_vals-1)/2);
			num_equal_vals = 1;
		}
	}
	ans_y+=(num_equal_vals*(num_equal_vals-1)/2);

	ll num_repeating = 0;
	ll r = 1;
	for(ll i=1; i<n; i++){
		if(points[i]==points[i-1]){
			r++;
		}else{
			num_repeating+=(r*(r-1)/2);
			r = 1;
		}
	}
	num_repeating+=(r*(r-1)/2);

	cout<<ans_x+ans_y-num_repeating;

	return 0;
}