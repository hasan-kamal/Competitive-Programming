/*
	
	@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <cstdlib>
#define N 100001
#define Q 200001
using namespace std;

struct trie_node{
	trie_node *one, *zero;
};

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;
typedef map<int, int> mii;

mii id_to_index = mii();
mii index_to_enc = mii();
vector<trie_node> vtrie_node;

int minimum(int x, int y){
	return x<y?x:y;
}

int maximum(int x, int y){
	return x>y?x:y;
}

void insert_root(int root_index, int k){
	trie_node *a = &vtrie_node[root_index];
	int i=30;
	while(i>=0){
		int bit = (k>>i)&1;
		if(bit==0){
			//bit==0
			a->zero = (trie_node *)malloc(sizeof(trie_node));
			a->zero->one = nullptr;
			a->zero->zero = nullptr;
			a = a->zero;
		}else{
			//bit==1
			a->one = (trie_node *)malloc(sizeof(trie_node));
			a->one->zero = nullptr;
			a->one->one = nullptr;
			a = a->one;
		}
		i--;
	}
}

void insert(int v_index, int u_index, int k){
	//u_index has encryption key k
	trie_node *a = &vtrie_node[u_index];
	trie_node *b = &vtrie_node[v_index];

	int i;
	for(i=30; i>=0; i--){
		int bit = (k>>i)&1; //have i-th bit
		if(bit==0){
			a->one = b->one;
			a->zero = (trie_node *)malloc(sizeof(trie_node));
			a->zero->one = nullptr;
			a->zero->zero = nullptr;
			a = a->zero;
			if(b->zero==nullptr)
				break;
			else
				b = b->zero;
		}else{
			//bit==1
			a->zero = b->zero;
			a->one = (trie_node *)malloc(sizeof(trie_node));
			a->one->zero = nullptr;
			a->one->one = nullptr;
			a = a->one;
			if(b->one==nullptr)
				break;
			else
				b = b->one;
		}
	}

	i--;
	while(i>=0){
		int bit = (k>>i)&1;
		if(bit==0){
			//bit==0
			a->zero = (trie_node *)malloc(sizeof(trie_node));
			a->zero->one = nullptr;
			a->zero->zero = nullptr;
			a = a->zero;
		}else{
			//bit==1
			a->one = (trie_node *)malloc(sizeof(trie_node));
			a->one->zero = nullptr;
			a->one->one = nullptr;
			a = a->one;
		}
		i--;
	}
}

void set_bit(int *a, int i){
	*a = (*a | (1<<i));
}

void unset_bit(int *a, int i){
	*a = (*a & (~(1<<i)) );
}

int get_min_xor(int index, int k){
	trie_node *a = &vtrie_node[index];
	int ans = 0;
	for(int i=30; i>=0; i--){
		int bit = (k>>i)&1;
		if(bit==0){
			//bit==0
			if(a->zero!=nullptr){
				a = a->zero;
				unset_bit(&ans, i);
			}else{
				a = a->one;
				set_bit(&ans, i);
			}
		}else{
			//bit==1
			if(a->one!=nullptr){
				a = a->one;
				unset_bit(&ans, i);
			}else{
				a = a->zero;
				set_bit(&ans, i);
			}
		}
	}
	return ans;
}

int get_max_xor(int index, int k){
	trie_node *a = &vtrie_node[index];
	int ans = 0;
	for(int i=30; i>=0; i--){
		int bit = (k>>i)&1;
		if(bit==0){
			//bit==0
			if(a->one!=nullptr){
				a = a->one;
				set_bit(&ans, i);
			}else{
				a = a->zero;
				unset_bit(&ans, i);
			}
		}else{
			//bit==1
			if(a->zero!=nullptr){
				a = a->zero;
				set_bit(&ans, i);
			}else{
				a = a->one;
				unset_bit(&ans, i);
			}
		}
	}
	return ans;
}

int main(){

	int n, q;
	cin>>n>>q;

	trie_node sample;
	sample.one = nullptr;
	sample.zero = nullptr;
	vtrie_node = vector<trie_node>(N+Q, sample);
	
	int r, encryption_key;
	cin>>r>>encryption_key;

	id_to_index[r] = 0;
	index_to_enc[0] = encryption_key;
	insert_root(0, encryption_key);

	int u, v, k;
	int index = 0;
	for(int i=0; i<n-1; i++){
		cin>>u>>v>>k;

		int u_index;
		if(id_to_index.find(u)!=id_to_index.end()){
			//this node is already assigned an index
			u_index = id_to_index[u];
		}else{
			//this is a new node, assign a new index
			u_index = ++index;
			id_to_index[u] = u_index;
			index_to_enc[u_index] = k;
		}

		int v_index;
		if(id_to_index.find(v)!=id_to_index.end()){
			v_index = id_to_index[v];
		}else{
			v_index = ++index;
			id_to_index[v] = v_index;
		}

		insert(v_index, u_index, k);
	}

	int last_answer = 0;
	while(q--){
		int t;
		cin>>t;
		t^=last_answer;

		if(t==0){
			cin>>v>>u>>k;
			u^=last_answer;
			v^=last_answer;
			k^=last_answer;

			int u_index = ++index;
			id_to_index[u] = u_index;
			index_to_enc[u_index] = k;
			
			int v_index = id_to_index[v];

			insert(v_index, u_index, k);
		}else{
			cin>>v>>k;
			v^=last_answer;
			k^=last_answer;

			int max = get_max_xor(id_to_index[v], k);
			int min = get_min_xor(id_to_index[v], k);
			cout<<min<<" "<<max<<endl;
			
			last_answer = min ^ max;
		}
	}

	return 0;
}