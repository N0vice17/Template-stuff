/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
class sparsetable {
    ll n, k;
    vector<vector<ll>> st;
public:
    ll combine(ll l, ll r) {
        return gcd(l, r);
    }
    sparsetable(const vector<ll>& arr) {
        n = arr.size();
        k = log2(n) + 1;
        st = vector<vector<ll>>(n, vector<ll>(k));
        build(arr);
    }
    ll query(ll L, ll R) {
        ll j = log2(R - L + 1);
        return combine(st[L][j], st[R - (1 << j) + 1][j]);
    }
private:
    void build(const vector<ll>& arr) {
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; (i + (1 << j) - 1) < n; i++) {
                st[i][j] = combine(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
};
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