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

vector<pii> frame_nodes;
vector<pii *> pointers_to_frame_nodes;
set<pii> p_queue;

int get_max_frame(){

}

void shift(){

}

int main(){

	cin>>n>>k>>p;

	vi a(n, 0);
	for(int i=0; i<n; i++)
		cin>>a[i];

	int x1 = 0;
	int sum = 0;
	for(int i=0; i<k; i++)
		sum+=a[i];
	int x2 = k-1;

	frame_nodes = vector<pii>(n-k+1);
	p_queue = set<pii>;
	int i=0;
	while(x2<n){
		frame_nodes[i].first = sum;
		frame_nodes[i].second = x2;
		pointers_to_frame_nodes[i] = &frame_nodes[i];

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
		if(str[j]=='?')
			cout<<get_max_frame();
		else{
			shift();
			num_shifts++;
		}
	}

	return 0;
}