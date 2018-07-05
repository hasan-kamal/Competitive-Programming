/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#define pb push_back
using namespace std;

typedef vector<int> vi;

class node{
public:
	int val;
	node* next;
	node(int v) : val(v){
		next = nullptr;
	}
};

class queue{
	node* head, *tail;
	int size;
public:
	queue(){
		head = tail = nullptr;
		size = 0;
	}

	void enqueue(int val){

		size++;
		if(head == nullptr){
			head = tail = new node(val);
			return;
		}

		tail->next = new node(val);
		tail =  tail->next;
	}

	int dequeue(){

		if(size <= 0)
			return -1;

		int val = head->val;
		head = head->next;
		if(size == 1)
			tail = nullptr;
		size--;
		return val;

	}

	int get_size(){
		return size;
	}
};

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue q;

	int v;
	while(n--){
		cin >> v;
		q.enqueue(v);
	}

	int n1, n2;
	cin >> n1 >> n2;

	while(n2--){
		vi val = vi();
		for(int i = 0; i < n1; i++){
			val.pb(q.dequeue());
		}
		int max_val_index = 0;
		for(int i = 1; i < val.size(); i++){
			if(val[i] > val[max_val_index])
				max_val_index = i;
		}
		for(int i = 0; i < val.size(); i++){
			if(i == max_val_index)
				continue;
			q.enqueue(val[i]);
		}
	}

	while(q.get_size() > 0){
		cout << q.dequeue() << " ";
	}

	return 0;
}