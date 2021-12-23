/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back
#define N (int)(1e5 + 1)
#define DEBUG 0
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

vvi adj_list;
ll n;

vi visited;
vvi children;
void dfs_get_children(ll s){
	//cout << "visiting s=" << s << endl;
	visited[s] = 1;
	for(ll nbour : adj_list[s]){
		if(visited[nbour] == 0){
			children[s].pb(nbour);
			dfs_get_children(nbour);
		}
	}
}

ll minimum(ll a, ll b){
	return a < b ? a : b;
}

const ll white = 0;
const ll black = 1;
const ll inf = 1e6;
ll dp[N][2][2][2];

//first values are white, second values are black
ll select_optimal_atleast_two_black(vii &v){

	// cout << "started f" << endl;
	// for(ii &p : v)
	// 	cout << "(" << p.first << ", " << p.second << ") ";
	// cout << endl;
	
	vi white_ind = vi();
	vi black_ind = vi();

	ll ans = 0;
	for(ll i = 0; i < v.size(); i++){
		if(v[i].first < v[i].second){
			ans += v[i].first;
			white_ind.pb(i);
		}else if(v[i].first > v[i].second){
			ans += v[i].second;
			black_ind.pb(i);
		}else{
			ans += v[i].second;
			black_ind.pb(i);
		}
	}

	if(black_ind.size() >= 2)
		return ans;

	ll num_black_more_needed = 2 - black_ind.size();

	ll new_ans = v.size() * (inf + 2) + 1;
	ll white_index_lost;
	for(ll w : white_ind){
		ll temp = ans - v[w].first + v[w].second;
		if(temp < new_ans){
			new_ans = temp;
			white_index_lost = w;
		}
	}

	if(num_black_more_needed == 1)
		return new_ans;

	vi::iterator pos = find(white_ind.begin(), white_ind.end(), white_index_lost);
	white_ind.erase(pos);
	black_ind.pb(white_index_lost);
	
	ll new_new_ans = v.size() * (inf + 2) + 1;
	for(ll w : white_ind){
		ll temp = new_ans - v[w].first + v[w].second;
		if(temp < new_new_ans){
			new_new_ans = temp;
		}
	}

	//cout << "ended f" << endl;

	return new_new_ans;
}

ll select_optimal_atleast_one_black(vii &v){
	
	ll min_val_sum = 0;
	bool took_black = false;
	for(ii &p : v){
		if(p.first < p.second)
			min_val_sum += p.first;
		else if(p.first > p.second){
			min_val_sum += p.second;
			took_black = true;
		}else{
			min_val_sum += p.second;
			took_black = true;
		}
	}

	if(took_black)
		return min_val_sum;

	ll ans = v.size() * (inf + 2) + 1;
	for(ii &p : v){
		ll temp = min_val_sum + (p.second - p.first);
		if(temp < ans)
			ans = temp;
	}

	return ans;

}

void entry_debug(ll offset, ll n, ll color, ll parent, ll sec_parent){

	if(!DEBUG)
		return;

	string spc = "";
	for(ll i = 0; i < offset; i++)
		spc += " ";
	cout << spc;
	cout << "entering n=" << n << " ";
	cout << "color=" << (color == white ? "white" : "black") << " ";
	cout << "parent=" << (parent == white ? "white" : "black") << " ";
	cout << "sec_parent=" << (sec_parent == white ? "white" : "black") << " ";
	cout << "dp=" << dp[n][color][parent][sec_parent];
	cout << endl;
}

void exit_debug(ll offset, ll n, ll color, ll parent, ll sec_parent){

	if(!DEBUG)
		return;

	string spc = "";
	for(ll i = 0; i < offset; i++)
		spc += " ";
	cout << spc;
	cout << "exiting n=" << n << " ";
	cout << "color=" << (color == white ? "white" : "black") << " ";
	cout << "parent=" << (parent == white ? "white" : "black") << " ";
	cout << "sec_parent=" << (sec_parent == white ? "white" : "black") << " ";
	cout << "dp=" << dp[n][color][parent][sec_parent];
	cout << endl;
}

ll f(ll offset_debug, ll n, ll color, ll parent, ll sec_parent){
	
	entry_debug(offset_debug, n, color, parent, sec_parent);

	if(dp[n][color][parent][sec_parent] >= 0)
		return dp[n][color][parent][sec_parent];

	if(children[n].size() == 0){
		//is a leaf
		if(color == white)
			dp[n][color][parent][sec_parent] = inf;
		else if(parent == white && sec_parent == white)
			dp[n][color][parent][sec_parent] = inf;
		else
			dp[n][color][parent][sec_parent] = 0;

		exit_debug(offset_debug, n, color, parent, sec_parent);
		return dp[n][color][parent][sec_parent];
	}

	if(color == white && parent == white){

		vii values = vii();
		if(children[n].size() < 2){
			//must have atleast two children, else not possible
			dp[n][color][parent][sec_parent] = inf;
			exit_debug(offset_debug, n, color, parent, sec_parent);
			return dp[n][color][parent][sec_parent];
		}
		for(ll i = 0; i < children[n].size(); i++){
			ll child = children[n][i];
			values.pb(make_pair(f(offset_debug + 1, child, white, white, white), f(offset_debug + 1, child, black, white, white) + 1));
		}

		dp[n][color][parent][sec_parent] = select_optimal_atleast_two_black(values);
		exit_debug(offset_debug, n, color, parent, sec_parent);
		return dp[n][color][parent][sec_parent];

	}

	if(color == white && parent == black){
		
		vii values = vii();
		for(ll i = 0; i < children[n].size(); i++){
			ll child = children[n][i];
			values.pb(make_pair(f(offset_debug + 1, child, white, white, black), f(offset_debug + 1, child, black, white, black) + 1));
		}

		dp[n][color][parent][sec_parent] = select_optimal_atleast_one_black(values);
		exit_debug(offset_debug, n, color, parent, sec_parent);
		return dp[n][color][parent][sec_parent];

	}

	if(color == black && (parent == black || sec_parent == black)){

		ll ans = 0;
		for(ll i = 0; i < children[n].size(); i++){
			ll child = children[n][i];
			ans += minimum(f(offset_debug + 1, child, white, black, parent), f(offset_debug + 1, child, black, black, parent) + 1);
		}
		dp[n][color][parent][sec_parent] = ans;
		exit_debug(offset_debug, n, color, parent, sec_parent);
		return ans;

	}

	if(color == black){
		// (parent == white && sec_parent == white) holds

		vii values = vii();
		for(ll i = 0; i < children[n].size(); i++){
			ll child = children[n][i];
			values.pb(make_pair(f(offset_debug + 1, child, white, black, parent), f(offset_debug + 1, child, black, black, parent) + 1));
		}

		dp[n][color][parent][sec_parent] = select_optimal_atleast_one_black(values);
		exit_debug(offset_debug, n, color, parent, sec_parent);
		return dp[n][color][parent][sec_parent];

	}

}

void show_adj_list(){
	for(ll i = 1; i <= n; i++){
		cout << i << "\'s neighbours are ";
		for(ll nbour : adj_list[i])
			cout << nbour << " ";
		cout << endl;
	}
	cout << endl;
}

void show_children(){
	for(ll i = 1; i <= n; i++){
		cout << i << "\'s children are ";
		for(ll child : children[i])
			cout << child << " ";
		cout << endl;
	}
	cout << endl;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin >> t;

	while(t--){
		cin >> n;
		if(n == 1){
			cout << "-1" << endl;
			continue;
		}

		ll u, v;
		adj_list = vvi(n + 1, vi());
		for(ll i = 0; i < n - 1; i++){
			cin >> u >> v;
			adj_list[u].pb(v);
			adj_list[v].pb(u);
		}

		//show_adj_list();
		visited = vi(n + 1, 0);
		children = vvi(n + 1, vi());
		dfs_get_children(1);
		//show_children();

		for(ll i = 0; i <= n; i++){
			for(ll j = 0; j < 2; j++)
				for(ll k = 0; k < 2; k++)
					for(ll l = 0; l < 2; l++)
						dp[i][j][k][l] = -1;
		}
		ll ans = minimum(f(0, 1, white, white, white), f(0, 1, black, white, white) + 1);
		cout << ans << endl;
	}

	return 0;
}