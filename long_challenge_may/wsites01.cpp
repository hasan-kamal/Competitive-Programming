#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;

#define LEN 200005
#define N 200005
#define ALPHABET 26

struct trie_node{
	trie_node *children[ALPHABET];
	bool is_leaf;
	bool is_marked;
};

trie_node *get_trie_node(){
	trie_node *new_node = (trie_node *)malloc(sizeof(trie_node));
	new_node->is_leaf = false;
	new_node->is_marked = false;
	for(int i=0; i<ALPHABET; i++)
		new_node->children[i] = NULL;
	return new_node;
}

void insert_trie(trie_node *root, char *str){
	if(str[0]=='\0'){
		root->is_leaf = true;
		return;
	}
	else{
		if(root->children[str[0]-'a']!=NULL)
			insert_trie(root->children[str[0]-'a'], str+1);
		else{
			root->children[str[0]-'a'] = get_trie_node();
			insert_trie(root->children[str[0]-'a'], str+1);
		}
	}
}

void show_trie(trie_node *root, int offset){
	if(root==NULL)
		return;

	for(int i=0; i<offset; i++)
				printf(" ");
	printf("->\n");
	for(int i=0; i<ALPHABET; i++){
		if(root->children[i]!=NULL){
			for(int i=0; i<offset; i++)
				printf(" ");
			
			printf("%c", 'a'+i);
			if(root->children[i]->is_leaf)
				printf("(leaf)");
			if(root->children[i]->is_marked)
				printf("(marked)");

			printf("\n");
		}
	}

	for(int i=0; i<ALPHABET; i++){
		if(root->children[i]!=NULL)
			show_trie(root->children[i], offset+1);
	}
}

//return negative if can never satisfy
int process_unblocked(trie_node *root, char *str){

	if(root->is_leaf)
		return -1; //not possible

	if(root->is_marked){
		root->is_marked = false;
		for(int i=0; i<ALPHABET; i++){
			if(root->children[i]!=NULL)
				root->children[i]->is_marked = true;
		}
	}

	if(str[0]=='\0'){
		return 1;
	}else{

		if(root->children[str[0]-'a']!=NULL){
			return process_unblocked(root->children[str[0]-'a'], str+1);
		}else{
			return 1; //exiting through a non-leaf node
		}

	}
}

//THIS PROGRAM IS CAUSING RESIGABRT
// int dfs_trie_get_answer(trie_node *root, string prefix, set<string> &filters){
// 	int k = 0;
// 	if(root->is_marked){
// 		k = 1;
// 		filters.insert(prefix);
// 	}

// 	for(int i=0; i<ALPHABET; i++){
// 		if(root->children[i]!=NULL){
// 			string new_character = string(1, (char)(i+'a'));
// 			k+=dfs_trie_get_answer(root->children[i], prefix+new_character, filters);
// 		}
// 	}

// 	return k;
// }

int dfs_trie_get_answer(trie_node *root, char *str, int len, set<string> &filters){
	int k = 0;
	if(root->is_marked){
		k = 1;
		filters.insert(string(str));
	}

	for(int i=0; i<ALPHABET; i++){
		if(root->children[i]!=NULL){
			//string new_character = string(1, (char)(i+'a'));
			str[len] = (char)(i+'a');
			str[len+1] = '\0';
			k+=dfs_trie_get_answer(root->children[i], str, len+1, filters);
		}
	}

	str[len] = '\0';

	return k;
}

void free_trie(trie_node *root){
	if(root==NULL)
		return;

	for(int i=0; i<ALPHABET; i++){
		if(root->children[i]!=NULL)
			free_trie(root->children[i]);
	}

	free(root);
}

set<string> filters = set<string>();
int main(){

	int n;
	scanf("%d\n", &n);

	char s[LEN];
	char ch;
	char *unblocked_sites[N];
	int num_unblocked = 0;

	trie_node *root = get_trie_node();
	root->is_marked = true;
	for(int i=0; i<n; i++){
		scanf("%c %s\n", &ch, s);
		if(ch=='-'){
			insert_trie(root, s);
		}else{
			unblocked_sites[num_unblocked++] = strdup(s);
		}
	}

	//show_trie(root, 0);
	// for(int i=0; i<ALPHABET; i++){
	// 	if(root->children[i]!=NULL)
	// 		root->children[i]->is_marked = true;
	// }

	for(int i=0; i<num_unblocked; i++){
		if(process_unblocked(root, unblocked_sites[i])<0){
			printf("-1");
			return 0;
		}
		//show_trie(root, 0);
		//printf("\n");
	}

	char str[N];
	str[0] = '\0';
	int k = dfs_trie_get_answer(root, str, 0, filters);
	printf("%d\n", k);
	for(set<string>::iterator it = filters.begin(); it!=filters.end(); it++){
		//printf("%s\n", (*it).c_str());
		cout<<*it<<endl;
	}

	free_trie(root);

	return 0;
}