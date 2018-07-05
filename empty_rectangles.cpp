#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define HH 0
#define VV 1
using namespace std;
const int SIZE = 2555;
int N,M,K,dd[SIZE][SIZE];
char s[SIZE][SIZE];
int get(int x1,int y1,int x2,int y2){
    x1--;y1--;
    return dd[x2][y2]-dd[x2][y1]-dd[x1][y2]+dd[x1][y1];
}
long long an;
void divide(int x1,int y1,int x2,int y2,int ty){
    if(ty==HH){
        if(x1==x2){
            for(int i=y1;i<=y2;i++){
                int cnt=0;
                for(int j=i;j<=y2&&cnt<=K;j++){
                    cnt+=s[x1][j];
                    if(cnt==K)an++;
                }
            }
            return;
        }
        int mm=(x1+x2)>>1;
        for(int i=y1;i<=y2;i++)
            for(int j=i;j<=y2;j++){
                int cnt[2][7]={};
                int ll=0,rr=mm-x1+1;
                for(int k=0;k<=K;k++){
                    if(k){
                        ll=cnt[0][k-1];
                        rr=mm-x1+1;
                    }
                    while(ll<rr){
                        int mid=(ll+rr+1)>>1;
                        if(get(mm-mid+1,i,mm,j)<=k)ll=mid;
                        else rr=mid-1;
                    }
                    cnt[0][k]=ll;
                }
                ll=0;rr=x2-mm;
                for(int k=0;k<=K;k++){
                    if(k){
                        ll=cnt[1][k-1];
                        rr=x2-mm;
                    }
                    while(ll<rr){
                        int mid=(ll+rr+1)>>1;
                        if(get(mm+1,i,mm+mid,j)<=k)ll=mid;
                        else rr=mid-1;
                    }
                    cnt[1][k]=ll;
                }
                for(int k=K;k>0;k--){
                    cnt[0][k]-=cnt[0][k-1];
                    cnt[1][k]-=cnt[1][k-1];
                }
                for(int k=0;k<=K;k++){
                    an+=cnt[0][k]*cnt[1][K-k];
                }
            }


        divide(x1,y1,mm,y2,ty^1);
        divide(mm+1,y1,x2,y2,ty^1);
    }
    else{
        if(y1==y2){
            for(int i=x1;i<=x2;i++){
                int cnt=0;
                for(int j=i;j<=x2&&cnt<=K;j++){
                    cnt+=s[j][y1];
                    if(cnt==K)an++;
                }
            }
            return;
        }
        int mm=(y1+y2)>>1;
        for(int i=x1;i<=x2;i++)
            for(int j=i;j<=x2;j++){
                int cnt[2][7]={};
                int ll=0,rr=mm-y1+1;
                for(int k=0;k<=K;k++){
                    if(k){
                        ll=cnt[0][k-1];
                        rr=mm-y1+1;
                    }
                    while(ll<rr){
                        int mid=(ll+rr+1)>>1;
                        if(get(i,mm-mid+1,j,mm)<=k)ll=mid;
                        else rr=mid-1;
                    }
                    cnt[0][k]=ll;
                }
                ll=0;rr=y2-mm;
                for(int k=0;k<=K;k++){
                    if(k){
                        ll=cnt[1][k-1];
                        rr=y2-mm;
                    }
                    while(ll<rr){
                        int mid=(ll+rr+1)>>1;
                        if(get(i,mm+1,j,mm+mid)<=k)ll=mid;
                        else rr=mid-1;
                    }
                    cnt[1][k]=ll;
                }
                for(int k=K;k>0;k--){
                    cnt[0][k]-=cnt[0][k-1];
                    cnt[1][k]-=cnt[1][k-1];
                }
                for(int k=0;k<=K;k++)an+=cnt[0][k]*cnt[1][K-k];
            }


        divide(x1,y1,x2,mm,ty^1);
        divide(x1,mm+1,x2,y2,ty^1);
    }
}
int main(){
    RIII(N,M,K);
    for(int i=1;i<=N;i++){
        RS(s[i]+1);
        for(int j=1;j<=M;j++){
            s[i][j]-='0';
            dd[i][j]=dd[i][j-1]+s[i][j];
        }
        for(int j=1;j<=M;j++)dd[i][j]+=dd[i-1][j];
    }
    divide(1,1,N,M,HH);
    cout<<an<<endl;
    return 0;
}