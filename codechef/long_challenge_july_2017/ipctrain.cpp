/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <queue>
#define D 100005
using namespace std;

typedef long long int ll;

class node{
public:
	ll id, d, t, s;
	node(ll id_, ll d_, ll t_, ll s_) : id(id_), d(d_), t(t_), s(s_){
		
	}
	void display(){
		cout << "node id=" << id << " ";
		cout << "d=" << d << " ";
		cout << "t=" << t << " ";
		cout << "s=" << s << " ";
		cout << endl;
	}
	bool operator<(const node& other) const{
		return s < other.s;
	}
};

typedef vector<node> vnode;
typedef vector<vnode> vvnode;
typedef priority_queue<node> pqnode;

int main(){

	ll t;
	cin >> t;

	ll n, d;
	ll di, ti, si;

	while(t--){
		cin >> n >> d;

		vvnode d_node = vvnode(D, vnode());
		for(ll i = 0; i < n; i++){
			cin >> di >> ti >> si;
			d_node[di].push_back(node(i, di, ti, si));
		}

		pqnode p = pqnode();
		for(ll i = 1; i <= d; i++){

			for(node n : d_node[i]){
				p.push(n);
			}

			if(!p.empty()){
				node max_s_node = p.top();
				p.pop();
				if(max_s_node.t > 1){
					max_s_node.t = max_s_node.t - 1;
					p.push(max_s_node);
				}
			}

		}

		ll ans = 0;
		while(!p.empty()){
			node n = p.top();
			p.pop();
			ans = ans + (n.s * n.t);
		}

		cout << ans << endl;
	}

	return 0;
}