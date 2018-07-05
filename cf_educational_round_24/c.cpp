/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class sofa{
public:
	int id, x1, y1, x2, y2;
};
typedef vector<sofa> vs;

void disp(vi &a, int start, int end){
	for(int i = start; i <= end; i++){
		cout << i << ")" << a[i] << " ";
	}
	cout << endl;
}

void disp_sofa(vs &a){
	for(sofa &s : a){
		cout << "id="<< s.id << " ";
	}
	cout << endl;
}

int main(){

	int d;
	cin >> d;

	int n, m;
	cin >> m >> n;

	vi left_val = vi(m + 1, 0);
	vi right_val = vi(m + 1, 0);
	vi down_val = vi(n + 1, 0);
	vi up_val = vi(n + 1, 0);

	vs sofas = vs(d);

	int x1, y1, x2, y2;
	for(int i = 0; i < d; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		
		sofas[i].id = i + 1;
		sofas[i].x1 = x1;
		sofas[i].x2 = x2;
		sofas[i].y1 = y1;
		sofas[i].y2 = y2;

		if(y1 == y2){
			//horizontal
			if(x1 > x2){
				int temp = x1;
				x1 = x2;
				x2 = temp;
			}
			left_val[x1]++;
			right_val[x2]++;
			up_val[y1]++;
			down_val[y1]++;
		}else{
			//vertical
			if(y1 < y2){
				int temp = y1;
				y1 = y2;
				y2 = temp;
			}
			up_val[y1]++;
			down_val[y2]++;
			left_val[x1]++;
			right_val[x2]++;
		}
	}

	int count_l, count_r, count_t, count_b;
	cin >> count_l >> count_r >> count_b >> count_t;

	for(int i = 2; i <= m; i++){
		left_val[i] = left_val[i] + left_val[i - 1];
	}

	for(int i = m - 1; i >= 0; i--){
		right_val[i] = right_val[i] + right_val[i + 1];
	}

	for(int i = n - 1; i >= 0; i--){
		up_val[i] = up_val[i] + up_val[i + 1];
	}

	for(int i = 2; i <= n; i++){
		down_val[i] = down_val[i] + down_val[i - 1];
	}

	// cout << "left_val" << endl;
	// disp(left_val, 1, m);
	// cout << "right_val" << endl;
	// disp(right_val, 1, m);
	// cout << "up_val" << endl;
	// disp(up_val, 1, n);
	// cout << "down_val" << endl;
	// disp(down_val, 1, n);

	vs sofas_fit_horizontal = vs();
	for(sofa& s : sofas){
		if(s.y1 == s.y2){
			//horizontal
			if(s.x1 > s.x2){
				int temp = s.x1;
				s.x1 = s.x2;
				s.x2 = temp;
			}
			if(left_val[s.x1] - 1 == count_l && right_val[s.x2] - 1 == count_r)
				sofas_fit_horizontal.push_back(s);
		}else{
			//vertical
			if(left_val[s.x1 - 1] == count_l && right_val[s.x1 + 1] == count_r)
				sofas_fit_horizontal.push_back(s);
		}
	}

	// cout << "sofas_fit_horizontal" << endl;
	// disp_sofa(sofas_fit_horizontal);

	vs ans = vs();
	for(sofa& s : sofas_fit_horizontal){
		if(s.y1 == s.y2){
			//horizontal
			if(up_val[s.y1 + 1] == count_t && down_val[s.y1 - 1] == count_b)
				ans.push_back(s);
		}else{
			//vertical
			if(s.y1 < s.y2){
				int temp = s.y1;
				s.y1 = s.y2;
				s.y2 = temp;
			}

			if(up_val[s.y1] - 1 == count_t && down_val[s.y2] - 1 == count_b)
				ans.push_back(s);
		}
	}

	if(ans.size() == 0)
		cout << "-1";
	else{
		cout << ans[0].id;
	}
	
	return 0;
}