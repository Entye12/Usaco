#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    
    vvi dp(n,vi(n,-1));
    int ans = 0;
    
    for (int i=n-1;i>=0;i--){
        dp[i][i] = a[i];
        for (int j=i;j<n;j++){
            for (int k=i;k<j;k++){
                if (dp[i][k] != -1 && dp[i][k] == dp[k+1][j]) dp[i][j] = dp[i][k]+1;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    
    cout << ans << endl;
    return 0;
}
