#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

typedef vector<int> vi;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c, s, set = 1;
	while(cin >> c >> s){
		vi spec(2 * c);
		double sum = 0.0;
		for(int i = 0; i < s; i++){
			cin >> spec[i];
			sum += spec[i];
		}
		for(int i = s; i < 2 * c; i++)
			spec[i] = 0;

		sort(spec.begin(), spec.end());

		cout << "Set #" << set << endl;
		double imb = 0.0, avg = sum / c;
		for(int i = 0; i < c; i++){
			cout << " " << i << ":";
			imb += abs(spec[i] + spec[2 * c - 1 - i] - avg);
			if(spec[i] > 0)
				cout << " " << spec[i];
			if(spec[2 * c - 1 - i] > 0)
				cout << " " << spec[2 * c - 1 - i];
			cout << endl;
		}

		set++;
		// printf("IMBALANCE = %.5lf\n\n", imb);
		cout << "IMBALANCE = " << setprecision(5) << fixed << imb << endl << endl;
	}

	return 0;
}