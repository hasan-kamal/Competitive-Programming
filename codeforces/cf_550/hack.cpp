// #include<bits/stdc++.h>
#include <iostream>
using namespace std;


int first_1(int *a){
	for(int i=0; i<26; i++){
		if(a[i]!=0)
			return i;
	}
}

int main(){
int n;
cin>>n;
while(n--){
	string s;
	cin>>s;
	int a[26];
	for(int i=0; i<26; i++){
		a[i]=0;
	}
	int l=s.length();
	for(int i=0; i<l; i++){
		char p=s[i];
		a[p-'a']++;
	}
	
	
	int p=first_1(a);
	int pl=p+l;
	int no=0;
	for(int i=p; i<min(pl,26); i++){
		if(a[i]!=1)
			no=1;
	}
	

	if(no==1)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
}
return 0;
}