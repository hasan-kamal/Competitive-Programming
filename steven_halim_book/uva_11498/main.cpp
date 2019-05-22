#include <iostream>
using namespace std;

int main(){

	int k;
	while(cin >> k){
		int n, m;
		cin >> n >> m;

		while(k--){
			int x, y;
			cin >> x >> y;
			x -= n;
			y -= m;

			if(x > 0){
				if(y > 0)
					cout << "NE" << endl;
				else if(y < 0)
					cout << "SE" << endl;
				else
					cout << "divisa" << endl;
			}else if(x < 0){
				if(y > 0)
					cout << "NO" << endl;
				else if (y < 0)
					cout << "SO" << endl;
				else
					cout << "divisa" << endl;
			}else{
				cout << "divisa" << endl;
			}
		}
	}

	return 0;
}