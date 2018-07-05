/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

void disp_vector(const vector<int> &v){
	for(int x : v)
		cout<<x<<" ";
	cout<<endl;
}

struct my_object{
	int x;
};

struct lt{
	inline bool operator()(const my_object& m1, const my_object& m2){
		return !(m1.x<m2.x);
	}
};

//Some points
/*

	Let’s return to the STL. STL algorithms always use two iterators, called “begin” and “end.”
	The end iterator is pointing not to the last object, however, but to the first invalid object, or the object directly following the last one.
	It’s often very convenient.
	Based on these principles, c.begin() == c.end() if and only if c is empty, and c.end() – c.begin() will always be equal to c.size().

*/

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	//creating vector of elements of 10 elements
	//initialised to a certain value
	vector<string> v(10, "hello");
	for(string s : v)
		cout<<s<<endl;

	v.empty(); //to check if empty
	int new_size = 0;
	v.resize(new_size); //to resize a vector
	v.clear(); //completely erases the container, to containing zero elements

	//custom comparator sorting
	vector<my_object> vm;
	vm.push_back(my_object{5});
	vm.push_back(my_object{6});
	sort(vm.begin(), vm.end(), lt());
	cout<<"custom sorting"<<endl;
	for(my_object &m : vm)
		cout<<m.x<<" ";
	cout<<endl;

	vector<int> vektor = {1, 2, 3};
	vi new_vector(vektor); //initialize a vector using existing vector
	vi new_vector2 = vektor; //initialize a vector using existing vector

	vector<int> v2(5, 10);
	for(auto x : v2)
		cout<<x<<endl;

	//creating matrices
	int n = 5;
	int m = 10;
	vector< vector<int> > matrix(n, vector<int>(m, -1));
	for(auto row : matrix){
		for(auto el : row)
			cout<<el<<" ";
		cout<<endl;
	}

	//reverse a part of vector
	vector<int> v4(10);
	for(int i=0; i<v4.size(); i++)
		v4[i] = i;
	disp_vector(v4);
	reverse(v4.begin(), v4.begin()+2);
	disp_vector(v4);

	//traversing using iterators
	vector<int> v5(10, -1);
	for(vector<int>::iterator it=v5.begin(); it!=v5.end(); it++){
		cout<<*it;
	}
	cout<<endl;

	//finding an element in vector
	vector<int> v6;
	for(int i=0; i<10; i++)
		v6.push_back(i*i);

	int index_49 = find(v6.begin(), v6.end(), 49) - v6.begin();
	if(index_49<v6.size()){
		cout<<"found"<<v6[index_49]<<endl;
	}

	//sort
	vector<int> v7 = {10, 90, 80, 7, 6};
	sort(v7.begin(), v7.end());
	//sort(v7.rbegin(), v7.rend()); //sort in descending order
	disp_vector(v7);

	// vector<int>::iterator it = v7.begin();
	// int i = 10;
	// while(i){
	// 	cout<<*it<<" ";
	// 	it++;
	// 	i--;
	// }

	//permutations
	vector<int> v8;
	for(int i=0; i<5; i++)
		v8.push_back(i);
	while(next_permutation(v8.begin(), v8.end()))
		disp_vector(v8);

	//copy
	vector<int> v9 = {5, 4, 3, 2, 1, 6, 7, 8, 9};
	vector<int> v10(20);
	copy(find(v9.begin(), v9.end(), 7), v9.end(), v10.begin());
	disp_vector(v10);

	return 0;
}