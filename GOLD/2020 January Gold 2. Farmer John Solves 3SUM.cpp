#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q;
    cin >> n >> q;
    
    vll a(n+1,0);
    for (int i=1;i<=n;i++) cin >> a[i];
    
    unordered_map<int,vll> dico;
    for (int k=1;k<=n;k++){
        if (!dico.count(a[k])) dico[a[k]].assign(n+1, 0);
        dico[a[k]][k]++;
    }
    
    for (auto &[key,value] : dico){
        for (int i=1;i<=n;i++) value[i] += value[i-1];
    }
    
    
    
    vvll dp(n+1, vll(n+1, 0));
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i+len-1 <= n; i++) {
            int j = i+len-1;
            ll x = 0;
            int target = -a[i] - a[j];
            if (dico.count(target)) {
                x = dico[target][j-1] - dico[target][i];
            }
            dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + x;
        }
    }
    
    while (q--){
        int i,j;
        cin >> i >> j;
        cout << dp[i][j] << '\n';
    }
    return 0;
}
