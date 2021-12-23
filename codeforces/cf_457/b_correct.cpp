/*

@author hasankamal

*/

#include <iostream>
#include <queue>
using namespace std;
typedef long long int ll;
typedef priority_queue<int> pq;

int main(){

	ll n, k;
	cin >> n >> k;

	pq q;
	for(int i = 62; i >=0; i--)
		if((n >> i) & 1)
			q.push(i);

	if(k < q.size()){
		cout << "No";
		return 0;
	}

	cout << "Yes" << endl;
	pq temp = q;
	int y = q.top();

	while(true){
		while(q.top() == y && q.size() < k){
			q.pop();
			q.push(y - 1);
			q.push(y - 1);
		}

		if(q.top() == y){
			// use temp, break smallest one there to achieve length k
			break;
		}

		// else, we have reduced y by 1
		temp = q;
		y = q.top();
	}

	// use temp, break smallest one there to achieve length k
	int count = 0;
	while(temp.size() > 1){
		cout << temp.top() << " ";
		temp.pop();
		count++;
	}

	// smallest element left
	count = k - count;
	int sm = temp.top();
	if(count == 1){
		cout << sm << " ";
		return 0;
	}

	for(int i = 1; i < count; i++){
		cout << sm - i << " ";
	}
	cout << sm - (count - 1) << " ";
	
	return 0;
}