/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

struct trie_node{
	trie_node *zero, *one;
	trie_node *parent;
	int count;
};

void free_trie(trie_node *root){
	if(root->zero!=nullptr)
		free_trie(root->zero);
	if(root->one!=nullptr)
		free_trie(root->one);
	free(root);
}

void insert_trie(trie_node *root, int val){
	for(int i=31; i>=0; i--){
		int bit = (val&(1<<i));
		if(bit==0){
			if(root->zero==nullptr){
				root->zero = (trie_node *)malloc(sizeof(trie_node));
				root->zero->zero = nullptr;
				root->zero->one = nullptr;
				root->zero->count = 0;
				root->zero->parent = root;
			}
			root = root->zero;
		}else{
			//bit==1
			if(root->one==nullptr){
				root->one = (trie_node *)malloc(sizeof(trie_node));
				root->one->zero = nullptr;
				root->one->one = nullptr;
				root->one->count = 0;
				root->one->parent = root;
			}
			root = root->one;
		}
	}
	root->count = root->count+1;
}

void erase_trie(trie_node *root, int val){

	for(int i=31; i>=0; i--){
		int bit = (val&(1<<i));
		if(bit==0){
			root = root->zero;
		}else{
			//bit==1
			root = root->one;
		}
	}

	if(root->count>1)
		root->count = root->count - 1;
	else{
		while(root->parent->zero==nullptr || root->parent->one==nullptr)
			root = root->parent;
		//remove all nodes starting from root
		
		if(root->parent->one==root)
			root->parent->one = nullptr;
		else if(root->parent->zero==root)
			root->parent->zero = nullptr;

		free_trie(root);
	}
}

int max_xor(trie_node *root, int val){
	int ans;

	for(int i=31; i>=0; i--){
		int bit = (val&(1<<i));
		
		if(bit==0){
			
			if(root->one!=nullptr){
				root = root->one;
				ans = ans | (1<<i);

			}else{
				root = root->zero;
				ans = ans & ~(1<<i);

			}

		}else{

			if(root->zero!=nullptr){
				root = root->zero;
				ans = ans | (1<<i);

			}else{
				root = root->one;
				ans = ans & ~(1<<i);
			}

		}
	}
	
	return ans;
}

int main(){

	trie_node *root = (trie_node *)malloc(sizeof(trie_node));
	root->zero = root->one = nullptr;
	root->count = 0;
	root->parent = root;
	insert_trie(root, 0);
		
	int q;
	cin>>q;

	char ch;
	int x;
	while(q--){

		cin>>ch;
		cin>>x;

		if(ch=='+'){
			insert_trie(root, x);
		}else if(ch=='-'){
			erase_trie(root, x);
		}else if(ch=='?'){
			cout<<max_xor(root, x)<<endl;
		}
	}

	free_trie(root);

	return 0;
}