#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define nline "\n"
#define MOD 1000000007
template<
        //find_by_order(k) -> this function returns an iterator to the kth element (counting from zero)
        //order_of_key(k) -> this function returns the number of items that are lesser than the given value k
        typename Key, // Key type
        typename Mapped, // Mapped-policy
        typename Cmp_Fn = less<Key>, // Key comparison functor
        typename Tag = rb_tree_tag, // Specifies which underlying data structure to use
        template<
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn_,
        typename Allocator_>
        class Node_Update = null_node_update, // A policy for updating node invariants
        typename Allocator = allocator<char> > // An allocator type
using ordered_set_tree=tree<Key,Mapped,Cmp_Fn,Tag,Node_Update,Allocator>;
typedef ordered_set_tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
vector<ll> sieve(ll n){
    vector<bool>arr(n+1,1);
    arr[0]=0;
    arr[1]=0;
    for(int i=2;i*i<=n;i++){
        if(arr[i]){
            for(int j=i*2;j<=n;j+=i){
                arr[j]=0;
            }
        }
    }
    vector<ll>arr1;
    for(int i = 1;i <= n;i++){
        if(arr[i]) arr1.push_back(i);
    }
    return arr1;
}
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
    ll ans=1,base=a;
    while(b>0){
        if(b%2==0){
            base=(base*base)%MOD;
            b=b/2;
        }
        else{
            ans=(ans*base)%MOD;
            b=b-1;
        }
    }
    return ans;
}
ll modulo_div(ll a,ll b,ll m){
    return mod_mul(a,binary_expo(b,m-2),m);
}
int main(){
    return 0;
}