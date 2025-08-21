#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

const int inf = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi c(n);
    for (int i=0;i<n;i++) cin >> c[i];
    
    vvi dp(n,vi(n,inf));
    
    for (int i=n-1;i>=0;i--){
        dp[i][i] = 1;
        for (int j=i;j<n;j++){
            if (c[i] == c[j] && i+1 < n && j>0){
                dp[i][j] = min(dp[i][j],dp[i][j-1]);
            } 
            else{
                for (int k=i;k<j;k++){
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    return 0;
}
