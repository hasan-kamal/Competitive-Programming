#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

typedef struct{
	int val;
	int row_index;
	char type;
} node;

int digit_count(char *str, int n){
	//forward
	int ans = INT_MAX;
	for(int i=0; i<n; i++){
		if(str[i]>='0' && str[i]<='9'){
			if(i<ans)
				ans = i;
		}
	}

	for(int i=n-1; i>=0; i++){
		
	}
}

int alphabet_count(char *str, int n){

}

int symbol_count(char *str, int n){

}

int main(){
	
	int n, m;
	cin>>n>>m;

	vector<node> v(3*n);

	char str[55];
	int i;
	for(i=0; i<n; i++){
		scanf("%s", str);

		node n1;
		n1.val = digit_count(str, m);
		n1.row_index = i;
		n1.type = 'd';
		v.push_back(n1);

		node n2;
		n2.val = alphabet_count(str, m);
		n2.row_index = i;
		n2.type = 'a';
		v.push_back(n2);

		node n3;
		n3.val = symbol_count(str, m);
		n3.row_index = i;
		n3.type = 's';
		v.push_back(n3);
	}

	sort(v);

	return 0;
}