/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;

class trie_node{
public:
	int count;
	trie_node *zero, *one;
	trie_node(){
		count = 0;
		left = right = nullptr;
	}
};

class trie{
public:
	trie_node* root;
	trie(){
		root = nullptr;
	}
	void insert(int v){

		trie_node * cur = root;

		int bit, i;
		for(i = 30; i >= 0; i--){
			int bit = ((v >> i) & 1);
			if(bit == 0){
				if(cur->zero == nullptr)
					break;
				cur = cur->zero;
			}else{
				if(cur->one == nullptr)
					break;
				cur = cur->one;
			}
		}

		while(i >= 0){
			int bit = ((v >> i) & 1);
			if(bit == 0){
				cur->zero = new trie_node();
				cur = cur->zero;
			}else{
				cur->one = new trie_node();
				cur = cur->one;
			}
			i--;
		}

		cur->val = cur->val + 1;
	}

	int num_equal(int val){
		trie_node * cur = root;

		int bit, i;
		bool broke = false;
		for(i = 30; i >= 0; i--){
			int bit = ((val >> i) & 1);
			if(bit == 0){
				if(cur->zero == nullptr){
					broke = true;
					break;
				}
				cur = cur->zero;
			}else{
				if(cur->one == nullptr){
					broke = true;
					break;
				}
				cur = cur->one;
			}
		}

		if(broke)
			return 0;

		return cur->val;
	}

	int num_smaller_equal_to(int val){
		
	}

	int num_bigger(int val){

	}
};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int n;
	while(t--){
		cin >> n;
		
		vi a = vi(n);
		for(int i = 0; i < n; i++)
			cin >> a[i];

		trie t;
		t.insert(a[0]);
		int ans = 0;
		for(int i = 1; i < n; i++){
			ans += t.num_smaller_equal_to(a[i]);
			ans += t.num_bigger(a[i]);
		}
		cout << ans << endl;
	}		

	return 0;
}