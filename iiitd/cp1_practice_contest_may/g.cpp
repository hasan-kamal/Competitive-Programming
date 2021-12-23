/*

@author Hasan Kamal

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<iii> viii;

vll ratings;
vll orders;
set<iii> p_queue;
vll running_sums;
ll n;

iii make_segment(ll start_index, ll end_index){
	ll sum;

	if(start_index==0){
		sum = running_sums[end_index];
	}else
		sum = running_sums[end_index] - running_sums[start_index-1];
	
	return make_pair(sum, make_pair(start_index, end_index));
}

int main(){

	ll t;
	
	cin>>t;
	while(t--){
		cin>>n;

		ratings = vll(n);
		orders = vll(n);
		running_sums = vll(n);
		
		for(ll i=0; i<n; i++)
			cin>>ratings[i];

		for(ll i=0; i<n; i++){
			cin>>orders[i];
			orders[i]--;
		}

		running_sums[0] = ratings[0];
		for(ll i=1; i<n; i++)
			running_sums[i]+=running_sums[i-1]+ratings[i];

		p_queue = set<iii>();
		iii first_segment = make_segment(0, n-1);
		p_queue.insert(first_segment);
		viii segments = viii(n, first_segment);
		int queue_size = 1;
		for(ll i=0; i<n; i++){
			ll dish_ordered = orders[i];

			if(ratings[dish_ordered]!=-1){
				//was availabe earlier, now make unavailable

				iii segment_hit = segments[dish_ordered];
				p_queue.erase(segments[dish_ordered]);
				queue_size--;
				
				iii s1, s2;
				if(dish_ordered-1>=0 && dish_ordered-1>=segment_hit.second.first){
					s1 = make_segment(segment_hit.second.first, dish_ordered-1);
					p_queue.insert(s1);
					for(int i=s1.second.first; i<=s1.second.second; i++)
						segments[i] = s1;
					queue_size++;
				}
				if(dish_ordered+1<n && dish_ordered+1<=segment_hit.second.second){
					s2 = make_segment(dish_ordered+1, segment_hit.second.second);
					p_queue.insert(s2);
					for(int i=s2.second.first; i<=s2.second.second; i++)
						segments[i] = s2;
					queue_size++;
				}

				ratings[dish_ordered] = -1;
			}

			if(queue_size>0)
				cout<<(*p_queue.rbegin()).first<<endl;
			else
				cout<<"0"<<endl;
		}		
	}

	return 0;
}