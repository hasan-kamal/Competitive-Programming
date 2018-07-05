/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct node{
	int value, running_sums;
	node *left, *right;
};

int n;
node *root = nullptr;

void insert(node *x, int value){
	if(x==nullptr){
		root = (node *)malloc(sizeof(node));
		root->value = value;
		root->running_sums = 0;
		root->left = root->right = nullptr;
		return;
	}

	if(value<x->value){
		//have to go left
		if(x->left!=nullptr)
			insert(x->left, value);
		else{
			x->left = (node *)malloc(sizeof(node));
			x->left->value = value;
			x->left->running_sums = 0;
			x->left->left = nullptr;
			x->left->right = nullptr;
		}
	}else{
		//have to go right
		if(x->right!=nullptr)
			insert(x->right, value);
		else{
			x->right = (node *)malloc(sizeof(node));
			x->right->value = value;
			x->right->running_sums = 0;
			x->right->left = nullptr;
			x->right->right = nullptr;
		}
	}
}

int a, b, lca;
int get_lca(node *x){
	if(x->value==a)
		return a;
	if(x->value==b)
		return b;

	if(a<x->value && b<x->value)
		return get_lca(x->left);
	else if(a>=x->value && b>=x->value)
		return get_lca(x->right);
	else
		return x->value;
}

int sum_a, sum_b, sum_lca;
void dfs_running_sums(node *s, int sum){
	s->running_sums = sum + s->value;
	
	if(s->value==a)
		sum_a = s->running_sums;
	if(s->value==b)
		sum_b = s->running_sums;
	if(s->value==lca)
		sum_lca = s->running_sums;
	
	if(s->left!=nullptr)
		dfs_running_sums(s->left, sum + s->value);

	if(s->right!=nullptr)
		dfs_running_sums(s->right, sum + s->value);
}

void free_tree(node *x){
	if(x->left!=nullptr)
		free_tree(x->left);

	if(x->right!=nullptr)
		free_tree(x->right);

	free(x);
}

int main(){

	cin>>n;
	int temp;
	for(int i = 0; i < n; i++){
		cin>>temp;
		insert(root, temp);
	}

	cin>>a>>b;
	lca = get_lca(root);
	dfs_running_sums(root, 0);

	cout<<sum_a+sum_b-2*sum_lca+lca;

	free_tree(root);

	return 0;
}