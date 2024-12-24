/*
* JAY SHREE RAM
* JAY SHREE GANESH
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
void joyshreeram() {
    ll n,m;
    cin >> n >> m;
    string str1,str2;
    cin >> str1 >> str2;
    vector<vector<ll>>dp(n,vector<ll>(m,-1));
    map<char,set<ll>>mpp1,mpp2;
    for(int i = 0;i < n;i++){
        mpp1[str1[i]].insert(i);
    }
    for(int i = 0;i < m;i++){
        mpp2[str2[i]].insert(i);
    }
    auto recur = [&] (auto &self,ll i,ll j) -> ll {
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(str1[i] == str2[j]){
            return dp[i][j] = self(self,i + 1, j + 1) + 1;
        }
        ll ans = 0;
        ans = max(ans,self(self,i + 1,j));
        ans = max(ans,self(self,i,j + 1));
        return dp[i][j] = ans;
    };
    ll length  = recur(recur,0,0);
    if(length <= 0){
        cout << 0 << "\n";
        return;
    }
    string lcs = "";
    ll x = 0,y = 0;
    while(x < n && y < m){
        if(str1[x] == str2[y]){
            lcs += str1[x];
            x += 1;
            y += 1;
        }
        else{
            if(x + 1 < n && dp[x][y] == dp[x + 1][y]){
                x += 1;
            }
            else if(y + 1 < m && dp[x][y] == dp[x][y + 1]){
                y += 1;
            }
            else{
                break;
            }
        }
    }
    cout << lcs << "\n";
    auto get = [&] (string str,map<char,set<ll>>mpp) -> ll {
        ll ans = INT_MAX;
        for(int i = 0;i < str.size();i++){
            ll tempfirst1 = i,templast1 = i - 1;
            bool check = true;
            for(auto it:lcs){
                auto it1 = mpp[it].upper_bound(templast1);
                if(it1 == mpp[it].end()){
                    check = false;
                    break;
                }
                templast1 = (*it1);
            }
            if(check){
                ans = min(ans,abs(tempfirst1 - templast1) + 1);
            }
        }
        return ans;
    };
    cout << 4 * length - (get(str1,mpp1) + get(str2,mpp2)) << "\n";
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
        int t = 1;
        // cin >> t;
        while (t--) {
            joyshreeram();
        }
    return 0;
}