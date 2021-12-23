/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define pb push_back
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

class person{
public:
	double x, v;
	person(ll _x, ll _v) : x(_x), v(_v){}
};

typedef vector<person> vp;
vp left_person, right_person;
double s;

double minimum(double a, double b){
	return a < b ? a : b;
}

double maximum(double a, double b){
	return a > b ? a : b;
}

vi segment_left;
vi segment_right;
bool p(double T){

	double l, r, d;

	for(int i = 0;  i <= 1e6 + 1; i++){
		segment_left[i] = 0;
		segment_right[i] = 0;
	}

	l = 0, r = 1e6;
	for(person& p : left_person){
		if(T < ((p.x) / p.v)){
			d = ( T * (s - p.v) * (s + p.v) + (p.x * p.v)) / s;
			l = p.x;
			r = d;

			r = minimum(r, 1e6 - 1);
			if(l > r){ //this was needed to avoid WA in test 5!
				continue;
			}
		}else{
			l = 1; r = 1e6 - 1;
		}

		segment_left[(ll)l]++;
		segment_left[(ll)(r + 1)]--;
	}

	l = 0, r = 1e6;
	for(person& p : right_person){
		if(T < ((1e6 - p.x + 0.0) / p.v)){
			d = ceil( ( (p.x * p.v) +  (s - p.v) * (1e6 - T*(s + p.v))) / s );
			l = d;
			r = p.x;

			l = maximum(l, 1);
			if(l > r){ //this was needed to avoid WA in test 5!
				continue;
			}
		}else{
			l = 1; r = 1e6 - 1;
		}
		segment_right[(ll)l]++;
		segment_right[(ll)(r + 1)]--;
	}

	for(int i = 1; i <= 1e6 + 1; i++){
		segment_left[i] += segment_left[i - 1];
		segment_right[i] += segment_right[i - 1];
	}

	for(int i = 1; i <= 1e6 - 1; i++){
		if(segment_left[i] > 0 && segment_right[i] > 0)
			return true;
	}
	return false;

}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	segment_left = vi(1e6 + 2, 0);
	segment_right = vi(1e6 + 2, 0);

	ll n;
	cin >> n >> s;

	double hi = -1;

	left_person = vp();
	right_person = vp();
	ll x, v, t;
	double tm;
	for(ll i = 0; i < n; i++){
		cin >> x >> v >> t;
		if(t == 1)
			left_person.pb(person(x, v));
		else
			right_person.pb(person(x, v));

		if(t == 1)
			tm = ((double)x) / v;
		else
			tm = (1e6 - (double)x) / v;

		if(tm > hi)
			hi = tm;
	}

	double tolerance = 1e-8;
	double lo = 0.0;
	double mid;
	while((hi - lo) >= tolerance){
		mid = lo + (hi - lo) / 2.0;
		if(p(mid))
			hi = mid;
		else
			lo = mid;
	}

	printf("%.30lf", mid); //should print in large precision!, also got WA in test 5 with simple cout, use printf in large precision for such questions!

	return 0;
}