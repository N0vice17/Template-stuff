/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define MOD 1000000007
#define ordered_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
class DSU{
   vector<ll>parent,size;
    DSU(ll n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 1;i <= n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    ll Find(ll v){
        if(parent[v] == v) return v;
        return parent[v] = Find(parent[v]);
    }
    void Union(ll u,ll v){
        ll u = Find(u);
        ll v = Find(v);
        if(u != v){
            if(size[v] < size[u]){
                swap(u,v);
            }
            parent[v] = u;
            size[u] += size[v];
        }
    }
};
void joyshreeram() {
   
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        joyshreeram();
    }
    return 0;
}