/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, d;

int go_up(int loc_id){
	int j = loc_id % m;
	int i = (loc_id - j) / m;

	int i_d = i - 1;
	int j_d = j;
	if(i_d < 0)
		return -1;
	return i_d * m + j_d;
}

int go_down(int loc_id){
	int j = loc_id % m;
	int i = (loc_id - j) / m;

	int i_d = i + 1;
	int j_d = j;
	if(i_d >= n)
		return -1;
	return i_d * m + j_d;
}

int go_left(int loc_id){
	int j = loc_id % m;
	int i = (loc_id - j) / m;

	int i_d = i;
	int j_d = j - 1;
	if(j_d < 0)
		return -1;
	return i_d * m + j_d;
}

int go_right(int loc_id){
	int j = loc_id % m;
	int i = (loc_id - j) / m;

	int i_d = i;
	int j_d = j + 1;
	if(j_d >= m)
		return -1;
	return i_d * m + j_d;
}

int id(ii loc){
	return loc.first * m + loc.second;
}

void bfs_block(vvi &adj_list, int source, vi &distance, vi &allowed){
	vi visited(n * m + 1, 0);
	queue<int> q;
	q.push(source);
	
	visited[source] = 1;
	distance[source] = 0;
	allowed[source] = 0;

	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		for(int nbour : adj_list[u]){
			if(visited[nbour] == 0){
				q.push(nbour);
				visited[nbour] = 1;
				distance[nbour] = distance[u] + 1;
				if(distance[nbour] <= d + 1)
					allowed[nbour] = 0;
			}
		}

	}
}

void bfs_again(vvi &adj_list, int source, vi &distance, vi &allowed){
	vi visited(n * m, 0);
	queue<int> q;
	q.push(source);

	visited[source] = 1;
	distance[source] = 0;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int nbour : adj_list[u]){
			if(allowed[nbour] == 0)
				continue;
			if(visited[nbour] == 0){
				q.push(nbour);
				visited[nbour] = 1;
				distance[nbour] = distance[u] + 1;
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> d;

	vvc grid(n, vc(m, '-'));
	vii monster_location;
	ii start, finish;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
			if(grid[i][j] == 'M')
				monster_location.push_back(make_pair(i, j));
			else if(grid[i][j] == 'S')
				start = make_pair(i, j);
			else if(grid[i][j] == 'F')
				finish = make_pair(i, j);
		}
	}

	vvi adj_list(n * m + 1, vi());
	vvi adj_list_no_dummy(n * m, vi());

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			ii loc = make_pair(i, j);
			
			if(go_up(id(loc)) != -1)
				adj_list[id(loc)].push_back(go_up(id(loc)));
			if(go_down(id(loc)) != -1)
				adj_list[id(loc)].push_back(go_down(id(loc)));
			if(go_left(id(loc)) != -1)
				adj_list[id(loc)].push_back(go_left(id(loc)));
			if(go_right(id(loc)) != -1)
				adj_list[id(loc)].push_back(go_right(id(loc)));

			if(go_up(id(loc)) != -1)
				adj_list_no_dummy[id(loc)].push_back(go_up(id(loc)));
			if(go_down(id(loc)) != -1)
				adj_list_no_dummy[id(loc)].push_back(go_down(id(loc)));
			if(go_left(id(loc)) != -1)
				adj_list_no_dummy[id(loc)].push_back(go_left(id(loc)));
			if(go_right(id(loc)) != -1)
				adj_list_no_dummy[id(loc)].push_back(go_right(id(loc)));
		}
	}

	// store a copy of graph without dummy node
	// vvi adj_list_no_dummy = adj_list;

	// adding dummy node
	for(ii monster : monster_location){
		// dummy id = n * m
		adj_list[n * m].push_back(id(monster));
		adj_list[id(monster)].push_back(n * m);
	}

	vi allowed(n * m + 1, 1);
	vi distance(n * m + 1, INT_MAX);
	bfs_block(adj_list, n * m, distance, allowed);

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		ii loc = make_pair(i, j);
	// 		if(allowed[id(loc)])
	// 			cout << ".";
	// 		else
	// 			cout << "X";
	// 	}
	// 	cout << endl;
	// }

	if( (allowed[id(start)] == 0) || (allowed[id(finish)] == 0) ){
		cout << "-1";
		// cout << endl;
		// cout << allowed[id(start)] << endl;
		// cout << allowed[id(finish)] << endl;
		return 0;
	}

	vi distance_new(n * m, INT_MAX);
	bfs_again(adj_list_no_dummy, id(start), distance_new, allowed);

	if(distance_new[id(finish)] == INT_MAX){
		cout << "-1";
	}else{
		cout << distance_new[id(finish)];
	}

	return 0;
}