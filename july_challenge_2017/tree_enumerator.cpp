/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

int f(int n);
int num_vertices_one_child;

int g(int num_children, int num_nodes){

	if(num_nodes < num_children)
		return 0;

	if(num_children == 1)
		return f(num_nodes);

	int ans = 0;
	for(int i = 1; i <= num_nodes + 1 - num_children; i++)
		ans += ( f(i) * g(num_children - 1, num_nodes - i) );

	return ans;

}

int f(int n){
	if(n == 0 || n == 1)
		return 1;

	int num_children;
	int ans = 0;
	for(num_children = 1; num_children <= n - 1; num_children++){

		ans += g(num_children, n - 1);
		if(num_children == 1)
			num_vertices_one_child += ans;

	}

	return ans;
}

int main(){

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++){
		num_vertices_one_child = 0;
		cout << "n=" << i << " number_trees=" << f(i) << " number_vertices_one_child=" << num_vertices_one_child << endl;
	}

	return 0;
}