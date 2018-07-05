/*

@author Hasan Kamal

*/

#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#define A 1000001
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<iii> viii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef set<ii> sii;
typedef vector<sii> vsii;

int block_size;
struct mo_comparator{
	inline bool operator()(const iii& query1, const iii& query2){
		int query1_block = (query1.first.first - 1) / block_size;
		int query2_block = (query2.first.first - 1) / block_size;
		if(query1_block != query2_block)
			return query1_block < query2_block;
		return query1.first.second < query2.first.second;
	}
};

vector<bool> is_prime;
map<int, int> prime_to_pos;
int calculate_primes(int n, vi &primes){
	is_prime = vector<bool>(n+1, true);
	is_prime[0] = false;
	is_prime[1] = true;
	for(int i = 2; i * i <= n; i++){
		for(int j = i * i; j <= n; j += i){
			if(is_prime[j])
				is_prime[j] = false;
		}
	}

	int num_primes = 0;
	for(int i = 2; i <= n; i++){
		if(is_prime[i]){
			primes.push_back(i);
			num_primes++;
			prime_to_pos[i] = num_primes;
		}
	}

	return num_primes;
}

vi seg;
void create_seg(int v, int l, int r){

}

vi tree;
int update_tree(int v, int l, int r, int x, int y){
	int num_iterations = 25;

	for(int i = 0; i < num_iterations; i++){
		tree[l-1] = tree[r-1] + i * i;
	}

	return tree[num_iterations];
}

void update_seg(int v, int l, int r, int x, int y){
	//printf(":v=%d l=%d r=%d x=%d y=%d\n", v, l, r, x, y);
	if(l <= x && x <= r){
		if(l == r){
			//leaf node
			seg[v] = seg[v] + y;
		}else{
			int mid = (l + r) / 2;
			update_seg(2 * v, l, mid, x, y);
			update_seg(2 * v + 1, mid + 1, r, x, y);

			seg[v] = seg[2 * v] + seg[2 * v + 1];
		}
	}
}

int query_seg(int v, int l, int r, int x, int y){
	if(x > r || y < l)
		return 0;
	else if(l>=x && y>=r)
		return seg[v];
	else{
		int mid = (l + r) / 2;
		return query_seg(2 * v, l, mid, x, y) + query_seg(2 * v + 1, mid + 1, r, x, y);
	}
}

int pos_first_prime_greater_than_equal_to(vi &primes, int lo, int hi, int x){
	
	int last_valid_index = hi;

	int mid;
	while(lo < hi){
		mid = lo + (hi - lo) / 2;
		if(primes[mid] >= x)
			hi = mid;
		else
			lo = mid + 1;
	}

	if(primes[lo] >= x)
		return lo;
	else{
		return last_valid_index + 1;
	}

}

int pos_last_prime_lesser_than_equal_to(vi &primes, int lo, int hi, int y){

	int mid;
	while(lo < hi){
		mid = lo + (hi - lo + 1) / 2;
		if(primes[mid] <= y)
			lo = mid;
		else
			hi = mid - 1;
	}

	if(primes[lo] <= y)
		return lo;
	else{
		return -1;
	}

}

int delay(int n){
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += i;
	return ans;
}

int main(){

	int n;
	scanf("%d", &n);

	vi primes;
	int num_primes = calculate_primes(A, primes);

	srand(time(NULL));
	//printf("%d\n", num_primes);
	//int num_primes = 78498;
	//vi primes = vi(num_primes);

	// vsii all_possible_factorizations = vsii(A, sii());
	// for(int i = 2; i < A; i++){
	// 	if(is_prime[i]){
	// 		ii e = make_pair(i, 1);
	// 		all_possible_factorizations[i].insert(e);
	// 		continue;
	// 	}
	// 	for(int p_index = 0; p_index < num_primes; p_index++){
	// 		if(i % primes[p_index] == 0){
	// 			all_possible_factorizations[i] = all_possible_factorizations[i / primes[p_index]];

	// 			int count = 0;
	// 			for(set<ii>::iterator it = all_possible_factorizations[i].begin(); it != all_possible_factorizations[i].end(); it++){
	// 				if(it->first == primes[p_index]){
	// 					count = it->second;
	// 					break;
	// 				}
	// 			}

	// 			if(count > 0){
	// 				all_possible_factorizations[i].erase(make_pair(primes[p_index], count));
	// 			}
	// 			all_possible_factorizations[i].insert(make_pair(primes[p_index], count + 1));

	// 			break;
	// 		}
	// 	}
	// }

	vi a = vi(n);

	vvii factorization = vvii(n, vii());
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		factorization[i].push_back(make_pair(2, 1));
		factorization[i].push_back(make_pair(3, 1));
		factorization[i].push_back(make_pair(5, 1));
		factorization[i].push_back(make_pair(7, 1));
		factorization[i].push_back(make_pair(11, 1));
		factorization[i].push_back(make_pair(13, 1));
		factorization[i].push_back(make_pair(17, 1));
		factorization[i].push_back(make_pair(19, 1));
		factorization[i].push_back(make_pair(23, 1));
		// for(set<ii>::iterator it = all_possible_factorizations[a[i]].begin(); it!=all_possible_factorizations[a[i]].end(); it++){
		// 	factorization[i].push_back(make_pair(prime_to_pos[it->first], it->second));
		// }

		// if(is_prime[a[i]]){
		// //	factorization[i].push_back(make_pair(prime_to_pos[a[i]], 1));
		// 	continue;
		// }

		// int prime_index = 0;
		// int count;
		// while(a[i] > 1){
		// 	count = 0;
		// 	while(a[i] % primes[prime_index] == 0){
		// 		a[i] /= primes[prime_index];
		// 		count++;
		// 	}
		// 	if(count != 0)
		// 		factorization[i].push_back(make_pair(prime_index + 1, count));
		// 	prime_index++;
		// }
	}

	//printf("here\n");
	//printf("factorization done\n");

	int q;
	scanf("%d", &q);

	int l, r, x, y;
	viii queries_mo_order = viii(q);
	vi xs = vi(q);
	vi ys = vi(q);
	for(int i = 0; i < q; i++){
		scanf("%d %d %d %d", &l, &r, &x, &y);
		queries_mo_order[i].first.first = l;
		queries_mo_order[i].first.second = r;
		queries_mo_order[i].second = i;
		xs[i] = x;
		ys[i] = y;
	}

	block_size = sqrt(n);
	sort(queries_mo_order.begin(), queries_mo_order.end(), mo_comparator());

	// for(iii &q : queries_mo_order){
	// 	//cout << "l=" << q.first.first << " r=" << q.first.second << endl;
	// 	printf("l=%d r=%d\n", q.first.first, q.first.second);
	// }

	//initialize segment tree
	//will have num_primes number of elements in it
	seg = vi(4 * num_primes + 1, 0);
	create_seg(1, 1, num_primes);
	tree = vi(4*num_primes + 1, 0);

	vi answers = vi(q);
	int mo_left = 0;
	int mo_right = -1;
	int X = 100000;
	int useless = 0;
	for(int i = 0; i < q; i++){
		l = queries_mo_order[i].first.first - 1;
		r = queries_mo_order[i].first.second - 1;
		x = xs[queries_mo_order[i].second];
		y = ys[queries_mo_order[i].second];

		while(mo_right < r){
			mo_right++;
			ii p = make_pair(1, 1);
		//	for(ii &p : factorization[mo_right]){
				//increase value of prime p.first by p.second in segment tree
				update_seg(1, 1, num_primes, p.first, p.second);
				//update_tree(1, 1, num_primes, p.first, p.second);
				//useless += delay(X--);
				//printf("%d\n", useless);
		//	}

			// int j = 0;
			// for(int x = 0; x < X; x++){
			// 	j++;
			// 	answers[0]++;
			// 	answers[0]--;
			// 	//printf("-\n");
			// }
			//delay(X);
		}

		while(mo_right > r){
			ii p = make_pair(1, 1);
		//	for(ii &p : factorization[mo_right]){
				//decrease value of prime p.first by p.second in segment tree
				update_seg(1, 1, num_primes, p.first, -1 * p.second);
				//update_tree(1, 1, num_primes, p.first, p.second);
				//useless += delay(X--);
		//	}
			// int j = 0;
			// for(int x = 0; x < X; x++){
			// 	j++;
			// 	answers[0]++;
			// 	answers[0]--;
			// 	//printf("-\n");
			// }
			//delay(X);
			mo_right--;
		}

		while(mo_left < l){
			ii p = make_pair(1, 1);
		//	for(ii &p : factorization[mo_left]){
				//decrease value of prime p.first by p.second in segment tree
				update_seg(1, 1, num_primes, p.first, -1 * p.second);
				//update_tree(1, 1, num_primes, p.first, p.second);
				//useless += delay(X--);
		//	}
			// int j = 0;
			// for(int x = 0; x < X; x++){
			// 	j++;
			// 	answers[0]++;
			// 	answers[0]--;
			// 	//printf("-\n");
			// }
			//delay(X);
			mo_left++;
		}

		while(mo_left > l){
			mo_left--;
			ii p = make_pair(1, 1);
		//	for(ii &p : factorization[mo_left]){
				//increase value of prime p.first by p.second in segment tree
				update_seg(1, 1, num_primes, p.first, p.second);
				//update_tree(1, 1, num_primes, p.first, p.second);
				//useless += delay(X--);
		//	}
			// int j = 0;
			// for(int x = 0; x < X; x++){
			// 	j++;
			// 	answers[0]++;
			// 	answers[0]--;
			// 	//printf("-\n");
			// }
			//delay(X);
		}


		int prime_index_start = 1 + pos_first_prime_greater_than_equal_to(primes, 0, num_primes - 1, x); // determine both these, should be 1-based indexing
		int prime_index_end = 1 + pos_last_prime_lesser_than_equal_to(primes, 0, num_primes - 1, y);
		//printf("start query\n");
		answers[queries_mo_order[i].second] = query_seg(1, 1, num_primes, prime_index_start, prime_index_end); //query sum of count of primes in range [x, y] in the segment tree
		//printf("end query\n");
	}

	//while(1);

	for(int i = 0; i < q; i++){
		//printf("%d\n", answers[i]);
	}

	return 0;
}
