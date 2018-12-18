#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef vector<vi> vvi;

vi color;
vvi adj_list;
int n, m;
string s;
bool ans;

vi stack;
map<int, int> pos;

bool check(int start, int end){
	cout << start << " " << end << endl;
	if(end - start + 1 % 2 == 1)
		return false;
	if(start == end)
		return false;
	if(s[stack[start]] == s[stack[start + 1]]){
		bool color_a = s[stack[start]] == 'A' ? true : false;
		for(int i = start + 2; i < end; i += 2){
			color_a = !color_a;
			if(color_a && s[stack[i]] == 'B'){
				return false;
			}
			if(!color_a && s[stack[i]] == 'A'){
				return false;
			}
			if(s[stack[i]] != s[stack[i + 1]]){
				return false;
			}
		}
		return true;
	}else{
		bool color_a = s[stack[start]] == 'A' ? true : false;
		for(int i = start + 1; i <= end; i += 2){
			color_a = !color_a;
			if(color_a && s[stack[i]] == 'B'){
				return false;
			}
			if(!color_a && s[stack[i]] == 'A'){
				return false;
			}
			if(i == end){
				if(s[stack[i]] != s[stack[start]]){
					return false;
				}
			}else{
				if(s[stack[i]] != s[stack[i + 1]]){
					return false;
				}
			}
		}
		return true;
	}
}

void special_visit(int source, int level){
	color[source] = 1;
	stack[level] = source;
	pos[source] = level;
	for(int nbour : adj_list[source]){
		if(color[nbour] == 0){
			special_visit(nbour, level + 1);
			if(ans == true)
				break;
		}else if(color[nbour] == 1){
			if(check(pos[nbour], level)){
				ans = true;
				break;
			}
		}
	}
	color[source] = 2;
}

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	cin >> s;

	adj_list = vvi(n);

	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--;
		b--;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}

	ans = false;
	color = vi(n, 0);
	stack = vi(n, 0);
	pos = map<int, int>();
	for(int i = 0; i < n; i++){
		if(color[i] == 0 && ans == false){
			special_visit(i, 0);
		}
	}

	if(ans)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}