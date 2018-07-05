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
	node* next;
	node* prev;
};

class circular_queue{
	node* head;
	node* tail;
public:
	circular_queue(int n){
		head = tail = nullptr;
		
		head = tail = new node;
		head->next = head->prev = head;
		head->val = 1;
			
		node* new_node;
		for(int i = 2; i <= n; i++){
			new_node = new node;
			new_node->val = i;
			new_node->prev = tail;
			tail->next = new_node;
			tail = new_node;
		}

		head->prev = tail;
		tail->next = head;
	}
	~circular_queue(){
		while(head != nullptr)
			delete_head();
	}
	void rotate(int num_times){
		while(num_times--){
			head = head->next;
			tail = tail->next;
		}
	}
	int get_head(){
		return (*head).val;
	}
	void delete_head(){

		if(head == tail){
			delete head;
			head = tail = nullptr;
			return;
		}

		node* cur = head;
		node* prev = head->prev;
		node* next = head->next;

		prev->next = next;
		next->prev = prev;
		delete head;

		head = next;
	}
};

int main(){

	int t, n;
	cin >> t;

	while(t--){
		cin >> n;
		circular_queue q = circular_queue(n);
		vi pos = vi(n + 1, -1);
		
		for(int x = 1; x <= n; x++){
			q.rotate(x);
			pos[q.get_head()] = x;
			q.delete_head();
		}

		for(int i = 1; i <= n; i++){
			cout << pos[i] << " ";
		}
		cout << endl;
	}

	return 0;
}