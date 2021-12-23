#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#define N 100001
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
int n, k, p;
int num_shifts;

vi a;
vector<pii> frame_nodes;
int head, tail;
set<pii> p_queue;

int get_max_frame(){
	return (*p_queue.rbegin()).first;
}

void shift(){
	p_queue.erase(frame_nodes[tail]);
	frame_nodes[tail].first = frame_nodes[head].first + a[frame_nodes[tail].second] - a[frame_nodes[head].second];
	frame_nodes[tail].second = frame_nodes[head].second - 1;
	if(frame_nodes[tail].second<0)
		frame_nodes[tail].second+=n;
	p_queue.insert(frame_nodes[tail]);

	//circular-shift the queue
	head = tail;
	tail = tail-1;
	if(tail<0)
		tail+=(n-k+1);
}

void debug(){
	cout<<"h:"<<head<<" t:"<<tail<<endl;
	for(set<pii>::iterator it = p_queue.begin(); it!=p_queue.end(); it++){
		cout<<":: "<<it->first<<" "<<it->second<<endl;
	}
	cout<<endl;
}

int main(){

	cin>>n>>k>>p;

	a = vi(n, 0);
	int sum = 0;
	for(int i=0; i<n; i++){
		cin>>a[i];
		sum+=a[i];
	}

	if(k>=n){
		char str[N];
		scanf("%s", str);
		int len = strlen(str);
		for(int j=0; j<len; j++){
			if(str[j]=='?'){
				//debug();
				cout<<sum<<endl;
			}
		}
		return 0;
	}

	int x1 = 0;
	sum = 0;
	for(int i=0; i<k; i++)
		sum+=a[i];
	int x2 = k-1;

	frame_nodes = vector<pii>(n-k+1);
	head = 0;
	tail = n-k;
	p_queue = set<pii>();
	int i=0;
	while(x2<n){
		frame_nodes[i].first = sum;
		frame_nodes[i].second = x2;
		p_queue.insert(frame_nodes[i]);

		sum-=a[x1];
		x1++;
		x2++;
		sum+=a[x2];

		i++;
	}



	num_shifts = 0;
	char str[N];
	scanf("%s", str);
	int len = strlen(str);
	for(int j=0; j<len; j++){
		if(str[j]=='?'){
			//debug();
			cout<<get_max_frame()<<endl;
		}
		else{
			shift();
			num_shifts++;
		}
	}

	return 0;
}