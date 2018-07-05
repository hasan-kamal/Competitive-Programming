/*

@author hasankamal

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef long long int ll;
typedef priority_queue<ll> pq;

int main(){

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, k;
	cin >> n >> k;
	
	pq q;
	for(int i = 63; i >= 0; i--){
		if((n >> i) & 1)
			q.push(i);
	}

	if(k < q.size()){
		cout << "No";
		return 0;
	}

	while(q.size() != k){
		ll highest = q.top();
		q.pop();
		q.push(highest - 1);
		q.push(highest - 1);
	}

	cout << "Yes" << endl;
	while(q.size() > 0){
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}