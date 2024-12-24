#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nline "\n"
#define MOD 1000000007
vector<vector<pair<ll,ll>>>blift(300001,vector<pair<ll,ll>>(21,{0,INT_MAX}));
vector<ll>depth(300001,0);
map<pair<ll,ll>,ll>mpp;
void dfs(vector<vector<ll>>&adj,ll node,ll parent){
    blift[node][0]={parent,min(blift[node][0].second,mpp[{parent,node}])};
    depth[node]=depth[parent]+1;
    for(int i=1;i<=20;i++){
        blift[node][i]={blift[blift[node][i-1].first][i-1].first,
                        min(blift[node][i-1].second,blift[blift[node][i-1].first][i-1].second)};
    }
    for(auto it:adj[node]){
        if(it!=parent)
            dfs(adj,it,node);
    }
}
ll query(ll u,ll v){
    if(depth[u]>depth[v]) swap(u,v);
    ll k=abs(depth[u]-depth[v]);
    ll ans=INT_MAX; 
    for(int i=0;i<=20;i++){
        if(((k>>i)&1)){
            ans=min(ans,blift[v][i].second);
            v=blift[v][i].first;
        }
    }
    for(int i=20;i>=0;i--){
        if(blift[u][i].first!=blift[v][i].first){
            ans=min({ans,blift[v][i].second,blift[u][i].second});
            v=blift[v][i].first;
            u=blift[u][i].first;
        }
    }
    if(u!=v){
        ans=min({blift[v][0].second,blift[u][0].second,ans});
    }
    return ans;
}