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
class SegmnetTree{
    vector<ll>segTree,segarray;
    SegmnetTree(ll n,vector<ll>&arr){
        segTree.resize(n * 4 + 1);
        segarray = arr;
    }
    // change according to the need
    ll operation(ll left,ll right){
        return left + right;
    }
    //building the segment tree
    void build(ll index,ll left,ll right){
        if(left == right){
            segTree[index] = segarray[left];
            return;
        }
        ll mid = (left + right) / 2;
        build(index * 2 + 1,left,mid);
        build(index * 2 + 2,mid + 1,right);
        segTree[index] = operation(segTree[index * 2 + 1],segTree[index * 2 + 2]);
    }
    //query for the segment tree
    ll query(ll index,ll left,ll right,ll start,ll end){
        if(left > end || right < start) return 0; // change according to the need
        if(left >= start && end <= right){
            return segTree[index];
        }
        ll mid = (left + right) / 2;
        ll leftval = query(index * 2 + 1,left,mid,start,end);
        ll rightval = query(index * 2 + 2,mid + 1,right,start,end);
        return operation(leftval,rightval); // change according to the need
    }
    //point update for the segment tree
    void update(ll index,ll left,ll right,ll value,ll ind){
        if(left == right){
            segTree[index] = value;
            return;
        }
        ll mid = (left + right) / 2;
        if(ind <= mid){
            update(index * 2 + 1,left,mid,value,ind);
        }
        else{
            update(index * 2 + 2 ,mid + 1,right,value,ind);
        }
        segTree[index] = operation(segTree[index * 2 + 1],segTree[index * 2 + 2]); // change according to the need
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