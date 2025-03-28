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
class BLift{
    vector<vector<ll>>adj,blift;
    vector<ll>depth;
    ll height;
    BLift(vector<vector<ll>>&arr,ll n){
        adj = arr;
        height = ceil(log2(n));
        blift = vector<vector<ll>>(n + 1,vector<ll>(height + 1,-1));
        depth.resize(n + 1,1);

        auto dfs = [&](auto &&self,ll node,ll par,ll level = 1) -> void {
            blift[node][0] = par;
            for(int i = 1;i <= height;i++){
                blift[node][i] = blift[blift[node][i - 1]][i - 1];
            }
            depth[node] = level;
            for(auto curr:adj[node]){
                if(curr != par){
                    self(self,curr,node,level + 1);
                }
            }
        };
    }
    ll Kancestor(ll node,ll k){
        for(int i = 0;i <= height;i++){
            if(((k >> i) & 1)){
                node = blift[node][i];
            }
        }
        return node;
    }
    ll LCA(ll u,ll v){
        if(depth[u] < depth[v]){
            v = Kancestor(v,abs(depth[u] - depth[v]));
        }
        else if(depth[v] < depth[u]){
            u = Kancestor(u,abs(depth[u] - depth[v]));
        }
        for(int i = height;i >= 0;i--){
            if(blift[u][i] != blift[v][i]){
                u = blift[u][i];
                v = blift[v][i];
            }
        }
        if(v == u) return v;
        return blift[u][0];
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