/*
 
Avishek Santhaliya.
Logic Magic 2016 - Maximum Money.
DPS Mathura Road.
 
*/
 
#include<bits/stdc++.h>
using namespace std ;
typedef long long int lli ;
const int MAX = 1e5 + 5 ;
int n , m ;
vector <int> v[MAX] ;
lli ans , val ;
bool vis[MAX] ;
int money[MAX] ;
 
//DFS Function to traverse each component
void dfs( int u )
{
    val += money[u] ;
    vis[u] = true ;
    int i ;
    for( i = 0 ; i < v[u].size() ; i++ )
    {
        int temp = v[u][i] ;
        if( !vis[temp] )
            dfs( temp ) ;
    }
}
//End of DFS function
int main()
{
    int t ;
    cin>>t;
    while( t-- )
    {
        int i ;
        //Initialization for every test case ( Clearing )
        ans = -1 ;
        for( i = 0 ; i < MAX ; i++ )
        {
            v[i].clear() ;
            vis[i] = false ;
        }
        //End of initialization
 
        //Taking Input
        cin>>n>>m ;
        for( i = 1 ; i <= n ; i++ )
            cin>>money[i] ;
        for( i = 0 ; i < m ; i++ )
        {
            int x , y ;
            cin>>x>>y ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        //End of input
 
        //DFS Traversal for every component
        for( i = 1 ; i <= n ; i++ )
        {
            //If the vertex is not visited means it is in another compenent, so visit it.
            if( !vis[i] )
            {
                val = 0 ;
                dfs( i ) ;
                if( val > ans )
                    ans = val ;
            }
        }
        //End of traversals, sfter each vertex is visited
 
        //Output
        cout<<ans<<endl;
    }
    return 0;
}