/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
vector<ll> sieve(ll n){
    vector<bool>arr(n + 1,1);
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2;i * i <= n;i++){
        if(arr[i]){
            for(int j = i * 2;j <= n;j += i){
                arr[j] = 0;
            }
        }
    }
    vector<ll>arr1;
    for(int i = 1;i <= n;i++){
        if(arr[i]) arr1.push_back(i);
    }
    return arr1;
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