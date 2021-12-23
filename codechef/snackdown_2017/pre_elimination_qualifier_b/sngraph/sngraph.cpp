/*

	@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
using namespace std;

// READ BEFORE SUBMITTING
// DO NOT USE INT!!
// C++11 required, range-based-for-loop has been used!!
// make_pair might create problems? please check

typedef long long int ll; //use only ll as m = n * n could overflow
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll minimum(ll x, ll y){
	return x < y ? x : y;
}

/* class connected_component starts */
struct connected_component{
	ll n, m;
	//vvll adj_list;
	map<ll, vll> adj_list;

	//preprocessing stuff
	ll min_val_d_at_which_entirely_disconnected;
	map<ll, ll> min_val_d_for_node_to_become_alone;
};

void preprocess_component(connected_component &c){
	//preprocess stuff

	//calculate degree of each vertex
	map<ll, ll> node_to_degree = map<ll, ll>();
	for(map<ll, vll>::iterator it = c.adj_list.begin(); it!=c.adj_list.end(); it++){
		node_to_degree[it->first] = (ll) it->second.size();
	}

	//min_val_d_at_which_entirely_disconnected
	map<pair<ll, ll>, ll> edges = map<pair<ll, ll>, ll>();
	ll max_val = 0;
	for(map<ll, vll>::iterator it = c.adj_list.begin(); it!=c.adj_list.end(); it++){
		for(ll nbour : it->second){
			ll temp = minimum(node_to_degree[it->first], node_to_degree[nbour]);
			edges[make_pair(it->first, nbour)] = temp;
			if(temp > max_val)
				max_val = temp;
		}
	}
	c.min_val_d_at_which_entirely_disconnected = max_val;

	//min_val_d_for_node_to_become_alone
	c.min_val_d_for_node_to_become_alone = map<ll, ll>();
	for(map<ll, vll>::iterator it = c.adj_list.begin(); it!=c.adj_list.end(); it++){
		ll u = it->first;
		
		ll temp_max = 0;
		for(ll v : c.adj_list[u]){
			pair<ll, ll> e = make_pair(u, v);
			if(edges[e] > temp_max)
				temp_max = edges[e];
		}
		c.min_val_d_for_node_to_become_alone[u] = temp_max;

	}
}

void disp_component(connected_component &c, ll i){
	cout << "component " << i << endl;
	cout << "\tn = " << c.n << ", m = " << c.	m << endl;
	for(map<ll, vll>::iterator it = c.adj_list.begin(); it!=c.adj_list.end(); it++){
		cout << "\t" << it->first << " -> ";
		for(ll nbour : it->second)
			cout << nbour << ", ";
		cout << endl;
	}
	cout << "\tmin_valid_d_at_which_entirely_disconnected = " << c.min_val_d_at_which_entirely_disconnected << endl;
	cout << "\tmin_valid_d_for_node_to_become_alone:" << endl;
	for(map<ll, ll>::iterator it = c.min_val_d_for_node_to_become_alone.begin(); it!=c.min_val_d_for_node_to_become_alone.end(); it++){
		cout << "\t for " << it->first << ", = " << it->second << endl;
	}
	cout << "---------" << endl;
}

/* class connected_component ends */

void dfs_visit(ll s, vll &visited, vvll &adj_list, ll n, vll &nodes_visited){
	visited[s] = 1;
	nodes_visited.push_back(s);
	for(ll nbour : adj_list[s]){
		if(visited[nbour] == 0)
			dfs_visit(nbour, visited, adj_list, n, nodes_visited);
	}
}

void break_into_connected_comp(vvll &adj_list, ll n, ll m, vector<connected_component> &ans){
	//store connected components into ans
	vll visited = vll(n, 0);

	ll num_components = 0;
	
	vll nodes_visited;
	for(int i = 0; i < n; i++){
		if(visited[i] == 0){
			num_components++;
			nodes_visited = vll();
			dfs_visit(i, visited, adj_list, n, nodes_visited);
			
			//make this component
			connected_component c;
			c.n = (ll) nodes_visited.size();
			c.adj_list = map<ll, vll>();
			c.m = 0;
			for(ll n : nodes_visited){
				c.adj_list[n] = adj_list[n];
				c.m += (ll) adj_list[n].size();
			}
			c.m /= 2;

			ans.push_back(c);
		}
	}

	//cout << "num_components = " << num_components << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	ll n, m;
	vvll adj_list;

	while(t--){
		cin >> n >> m;

		adj_list = vvll(n, vll());
		ll u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			u--;
			v--;
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		
		vector<connected_component> components;
		break_into_connected_comp(adj_list, n, m, components);
		
		for(connected_component &c : components)
			preprocess_component(c);

		// ll i = 1;
		// for(connected_component &c : components)
		// 	disp_component(c, i++);

		//prepare timeline of (t, is_component_gone)
		set< pair<ll, pair<ll, bool> > > timeline = set< pair<ll, pair<ll, bool> > >();
		ll timeline_size = 0;
		ll component_id = 0;
		for(connected_component &c : components){
			//for(ll n : c.min_val_d_for_node_to_become_alone){
			for(map<ll, ll>::iterator it = c.min_val_d_for_node_to_become_alone.begin(); it!=c.min_val_d_for_node_to_become_alone.end(); it++){
				//timeline.insert(make_pair(make_pair(it->second, it->first), false)); //adding node id because we want repititions to exist
				timeline.insert(make_pair(it->second, make_pair(it->first, false))); //adding node id because we want repititions to exist
				timeline_size++;
			}
			//timeline.insert(make_pair(make_pair(c.min_val_d_at_which_entirely_disconnected, component_id++), true)); //adding component id because we want repititions to exist
			timeline.insert(make_pair(c.min_val_d_at_which_entirely_disconnected, make_pair(component_id++, true))); //adding component id because we want repititions to exist
			timeline_size++;
		}

		ll d = 0;

		ll ans = 0;
		ll current_time = 0;
		ll num_connected_components = (ll) components.size();
		
		while(timeline_size > 0){
			
			pair<ll, pair<ll, bool> > t = *timeline.begin();
			while( t.first == current_time ){
				if(t.second.second == false)
					ans = ans + 1;
				else
					num_connected_components--;

				timeline.erase(t);
				
				//cout << "\t" << t.second.first << " at d = " << d << " is__component_gone:" << t.second.second << " num_connected_components=" << num_connected_components << endl;
				
				timeline_size--;
				if(timeline_size == 0){
					break;
				}
				t = *timeline.begin();
			}
			
			//print ans + num_connected_components - 1
			for(int x = 0; x < t.first - current_time; x++){
				cout << ans + num_connected_components - 1 << " ";
				d++;
			}

			current_time = t.first;
		}

		while(d < n){
			cout << n - 1 << " ";
			//cout << ans + num_connected_components - 1 << " ";
			d++;
		}

		cout << endl;
	}

	return 0;
}