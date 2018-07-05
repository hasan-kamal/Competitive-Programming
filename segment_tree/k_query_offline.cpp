/*

@author Hasan Kamal

*/

#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

typedef vector<int> vi;
typedef struct{
	int i, j, k, online_index;
} query;
typedef vector<query> vq;
typedef pair<int, query> piq;
typedef vector<piq> vpiq;

struct custom_compare{
	//return true if first argument should appear first than second argument after sort() is called
	
	inline bool operator() (const piq &x, const piq &y){
		if(x.first > y.first){
			return true;
		}else if(x.first == y.first){
			if(x.second.i != 0)
				return true;
			else if(y.second.i != 0)
				return false;
		}

		return false;

	}

};

vi a;
vi tree;
void build_tree(int v, int start, int end){
	
	if(start == end){
		tree[v] = 0;
		return;
	}

	int mid = start + ( end - start ) / 2;
	build_tree(2 * v, start, mid);
	build_tree(2 * v + 1, mid + 1, end);
	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

void update_tree(int v, int start, int end, int index_added){

	if(start == end){
		tree[v]++;
		return;
	}

	int mid = start + (end - start) / 2;
	if(mid < index_added){
		update_tree(2 * v + 1, mid + 1, end, index_added);
	}else if(index_added <= mid){
		update_tree(2 * v, start, mid, index_added);
	}
	//other case not needed as we're adding only one index at a time
	tree[v] = tree[2 * v] + tree[2 * v + 1];

}

int query_tree(int v, int start, int end, int l, int r){

	if(start == l && end == r){
		return tree[v];
	}

	int mid = start + (end - start) / 2;
	if(mid < l){
		return query_tree(2 * v + 1, mid + 1, end, l, r);
	}else if(r <= mid){
		return query_tree(2 * v, start, mid, l, r);
	}

	return query_tree(2 * v, start, mid, l, mid) + query_tree(2 * v + 1, mid + 1, end, mid + 1, r);

}

void disp_tree(int v, int start, int end, int indentation){
	
	string str = "";
	for(int i = 0; i < indentation; i++)
		str += "\t";

	//cout << str << "node v=" << v << " [" << start << ", " << end << "] tree[v]=" << tree[v] << endl;
	if(start == end){
		return;
	}

	int mid = start + (end - start) / 2;
	disp_tree(2 * v, start, mid, indentation + 1);
	disp_tree(2 * v + 1, mid + 1, end, indentation + 1);

}

int main(){

	int n;
	scanf("%d", &n);

	a = vi(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int q;
	scanf("%d", &q);

	vq queries = vq(q);
	for(int i = 0; i < q; i++){
		scanf("%d %d %d", &queries[i].i, &queries[i].j, &queries[i].k);
		queries[i].online_index = i;
	}

	vpiq everything = vpiq(n + q);
	for(int i = 0; i < n; i++){
		everything[i].first = a[i];
		everything[i].second.i = 0;
		everything[i].second.j = 0;
		everything[i].second.k = i + 1;
	}

	for(int i = 0; i < q; i++){
		everything[n + i].first = queries[i].k;
		everything[n + i].second = queries[i];
	}

	sort(everything.begin(), everything.end(), custom_compare());

	tree = vi(4 * n);
	build_tree(1, 1, n);

	vi ans = vi(q);
	for(int i = 0; i < n + q; i++){
		if(everything[i].second.i == 0){
			update_tree(1, 1, n, everything[i].second.k);
		}else{
			ans[ everything[i].second.online_index ] = query_tree(1, 1, n, everything[i].second.i, everything[i].second.j);
		}
	}

	for(int i = 0; i < q; i++)
		printf("%d\n", ans[i]);

	return 0;
}