/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

class my_object{
private:
	int x, y;
public:
	inline bool operator<(const my_object& other) const{
		return x < other.x;
	}
	my_object(int a, int b){
		x = a;
		y = b;
	}
	int get_x(){
		return x;
	}
	int get_y(){
		return y;
	}
};

typedef vector<my_object> vm;

int main(){

	vm v = vm();

	v.push_back(my_object(4, 100));
	v.push_back(my_object(2, 20));

	for(my_object& m : v)
		cout << m.get_x() << " " << m.get_y() << endl;
	cout << endl;

	sort(v.begin(), v.end());

	for(my_object& m : v)
		cout << m.get_x() << " " << m.get_y() << endl;
	cout << endl;

	return 0;
}