/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll mod_add(ll a,ll b,ll m){
    return (a % m + b % m) % m;
}
ll mod_minus(ll a,ll b,ll m){
    return (a % m - b % m) % m;
}
ll mod_mul(ll a,ll b,ll m){
    return (a % m * b % m) % m;
}
ll binary_expo(ll a,ll b){
    ll ans = 1,base = a;
    while(b > 0){
        if(b % 2 == 0){
            base = (base * base) % MOD;
            b = b / 2;
        }
        else{
            ans = (ans * base) % MOD;
            b = b - 1;
        }
    }
    return ans;
}
ll modulo_div(ll a,ll b,ll m){
    return mod_mul(a,binary_expo(b,m - 2),m);
}
void joyshreeram() {
   
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
        int t;
        cin >> t;
        while (t--) {
            joyshreeram();
        }
    return 0;
}