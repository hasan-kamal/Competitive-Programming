#include <iostream>
#include <vector>
#define ALPHABET_SIZE 26
using namespace std;

class Node{
	char value;
	vector<Node *> children;
	bool is_end;
public:
	Node(char value_, bool is_end_) : value(value_), is_end(is_end_){
		children = vector<Node *>(ALPHABET_SIZE, NULL);
	}

	Node() : Node('\0', false){ }

	Node *get_child(char character) const{
		return children[character - 'a'];
	}

	void set_child(char character, Node *child){
		children[character - 'a'] = child;
	}

	void set_is_end(bool is_end_){
		is_end = is_end_;
	}

	bool get_is_end() const{
		return is_end;
	}
};


class Trie{
	Node *root;
	Node *traverse(const string &s);
	vector<string> get_strings_in_subtrie(const Node *root);
	void rfree(Node *root);
public:
	Trie() : root(new Node()){ }
	void insert(const string& s);
	bool exists(const string& s);
	vector<string> prefix_match(const string& prefix);
	void free();
};

Node *Trie::traverse(const string& s){
	Node *current = root;
	for(int i = 0; i < s.length(); i++){
		if(current->get_child(s[i]) == NULL){
			return NULL;
		}
		current = current->get_child(s[i]);
	}
	return current;
}

void Trie::insert(const string& s){
	Node *current = root;
	for(int i = 0; i < s.length(); i++){
		if(current->get_child(s[i]) == NULL){
			current->set_child(s[i], new Node(s[i], false));
		}
		current = current->get_child(s[i]);
	}
	current->set_is_end(true);
}

bool Trie::exists(const string& s){
	Node *node = traverse(s);
	return node == NULL ? false : node->get_is_end();
}

vector<string> Trie::get_strings_in_subtrie(const Node *root){
	if(root == NULL)
		return vector<string>();
	vector<string> ans;
	if(root->get_is_end())
		ans.push_back("");
	for(char ch = 'a'; ch <= 'z'; ch++){
		vector<string> sub_results = get_strings_in_subtrie(root->get_child(ch));
		for(const string& s : sub_results)
			ans.push_back(ch + s);
	}
	return ans;
}

vector<string> Trie::prefix_match(const string& prefix){
	Node *node = traverse(prefix);
	if(node == NULL)
		return vector<string>();
	vector<string> sub_results = get_strings_in_subtrie(node);
	vector<string> ans(sub_results.size(), "");
	for(int i = 0; i < ans.size(); i++)
		ans[i] = prefix + sub_results[i];
	return ans;
}

void Trie::rfree(Node *root){
	if(root == NULL)
		return;
	for(char ch = 'a'; ch <= 'z'; ch++){
		rfree(root->get_child(ch));
	}
	delete root;
}

void Trie::free(){
	rfree(root);
}

int main(){

	Trie trie;

	vector<string> strings = {"abc", "abdef", "azop"};
	for(const string& s : strings){
		trie.insert(s);
	}

	int n;
	cin >> n;

	string query;
	while(n--){
		cin >> query;
		if(trie.exists(query))
			cout << "exists" << endl;
		else
			cout << "does not exist" << endl;
	}
	
	cin >> n;
	string prefix_query;
	while(n--){
		cin >> prefix_query;
		vector<string> matching_strings = trie.prefix_match(prefix_query);
		for(const string& s : matching_strings)
			cout << s << endl;
	}

	trie.free();

	return 0;
}