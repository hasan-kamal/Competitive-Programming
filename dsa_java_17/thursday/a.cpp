/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class node{
public:
	int val;
	node* next, *prev;
	node(int v_) : val(v_){
		next = nullptr;
		prev = nullptr;
	}
};

class circular_list{
	node* head, *tail;
	int sz;
public:
	circular_list(int n){
		head = new node(1);
		tail = head;
		for(int i = 2; i <= n; i++){
			node* n = new node(i);
			tail->next = n;
			n->prev = tail;
			tail = n;
		}
		tail->next = head;
		head->prev = tail;
		sz = n;
	}

	void play(){
		node* dest = head->next->next;
		node* temp = head->next;

		head->next = dest;
		dest->prev = head;
		delete temp;

		head = dest;
		sz--;
	}

	int get_head(){
		return head->val;
	}

	int get_size(){
		return sz;
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
		circular_list l(n);
		while(l.get_size() > 1){
			l.play();
		}
		cout << l.get_head() << endl;
	}

	return 0;
}