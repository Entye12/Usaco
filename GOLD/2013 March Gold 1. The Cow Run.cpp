#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define all(x) (x).begin(), (x).end()

const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi left{0},right{0};
    
    for (int i=0;i<n;i++){
        int x;
        cin >> x;
        if (x>0) right.push_back(x);
        else left.push_back(x);
    }
    
    sort(all(right));
    sort(all(left),greater<>());
    
    int r = right.size();
    int l = left.size();
    
    vector<vector<vi>> dp(r,vvi(l,vi(2,inf)));
    
    dp[0][0][0] = 0; dp[0][0][1] = 0;
    
    for (int i=0;i<r;i++){
        for (int j=0;j<l;j++){
            if (i>0){
                if (dp[i-1][j][0] < inf){
                    dp[i][j][0] = min(dp[i][j][0],
                    dp[i-1][j][0] + (right[i] - right[i-1])*(n-(i-1+j)));
                }
                if (dp[i-1][j][1] < inf){
                    dp[i][j][0] = min(dp[i][j][0],
                    dp[i-1][j][1] + abs(right[i]-left[j])*(n-(i-1+j)));
                }
            }
            if (j>0){
                if (dp[i][j-1][1] < inf){
                    dp[i][j][1] = min(dp[i][j][1],
                    dp[i][j-1][1] + abs(left[j]-left[j-1])*(n-(i+j-1)));
                }
                if (dp[i][j-1][0] < inf){
                    dp[i][j][1] = min(dp[i][j][1],
                    dp[i][j-1][0] + abs(left[j]-right[i])*(n-(i+j-1)));
                }
            }
        }
    }
    
    int ans = min(dp[r-1][l-1][0],dp[r-1][l-1][1]);
    cout << ans << endl;

    return 0;
}
