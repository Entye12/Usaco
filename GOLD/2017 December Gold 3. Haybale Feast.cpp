#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; ll m;
    cin >> n >> m;
    
    ll ans = 1e9+1;
    
    vll f(n+1,0),s(n+1,0);
    for (int i=1;i<=n;i++) cin >> f[i] >> s[i];
    deque<ll> dq;
    
    ll sum = 0;
    int r = 1;
    for (int l=1;l<=n;l++){
        while (r<=n && sum < m){
            sum += f[r];
            while (!dq.empty() && dq.back() < s[r]) dq.pop_back();
            dq.push_back(s[r]);
            r++;
        }
        
        if (sum >= m && !dq.empty()) ans = min(ans,dq.front());
        
        sum -= f[l];
        if (!dq.empty() && dq.front() == s[l]) dq.pop_front();
    }
    
    cout << ans << endl;
    return 0;
}
