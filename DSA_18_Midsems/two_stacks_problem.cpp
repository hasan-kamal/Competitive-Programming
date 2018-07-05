// https://www.hackerrank.com/challenges/game-of-two-stacks/problem

#include <bits/stdc++.h>
#define DEBUG 0

using namespace std;
typedef long long int ll;

int main(){
    ll g;
    cin >> g;
    for(ll a0 = 0; a0 < g; a0++){
        ll n;
        ll m;
        ll x;
        cin >> n >> m >> x;
        vector<ll> a(n);
        for(ll a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        vector<ll> b(m);
        for(ll b_i = 0; b_i < m; b_i++){
           cin >> b[b_i];
        }
        
        ll a_sum = 0;
        ll a_index = -1;
        while(a_index + 1 < n && a[a_index + 1] + a_sum <= x){
            a_sum += a[a_index + 1];
            a_index++;
        }
        ll a_top = 0;
        
        ll b_sum = 0;
        ll b_index = -1;
        while(b_index + 1 < m && b[b_index + 1] + b_sum <= x){
            b_sum += b[b_index + 1];
            b_index++;
        }
        ll b_top = 0;
        
        ll ans = 0;
        ll cost = 0;
        while(cost <= x){
            if(a_index < a_top && b_index < b_top)
                break;
            if(a_index - a_top + 1 >= b_index - b_top + 1){
                cost += a[a_top];
                a_sum -= a[a_top];
                a_top++;
                if(cost > x)
                    break;
                ans++;
                while(b_sum > x - cost){
                    b_sum -= b[b_index];
                    b_index--;
                }
                if(DEBUG) cout << "->a " << a[a_top - 1] << " b_index " << b_index << endl;
            }else{
                cost += b[b_top];
                b_sum -= b[b_top];
                b_top++;
                if(cost > x)
                    break;
                ans++;
                while(a_sum > x - cost){
                    a_sum -= a[a_index];
                    a_index--;
                }
                if(DEBUG) cout << "->b " << b[b_top - 1] << " a_index " << a_index << " " << a_sum << endl; 
            }
        }
        
        cout << ans << endl;
        
    }
    return 0;
}
