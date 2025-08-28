#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using vi = vector<int>;
#define all(x) (x).begin(),(x).end()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vi c(n+2,0);
    for (int i=1;i<=n;i++) cin >> c[i];
    
    unordered_set<int> visited{0};
    
    unordered_map<int,int> rightIdx;
    for (int i=1;i<=n;i++) rightIdx[c[i]] = i;
    
    int ans = 0;
    stack<pii> s;
    
    for (int i=1;i<=n;i++){
        if (visited.count(c[i])) continue;
        int start = i; int end = rightIdx[c[i]];
        while (!s.empty() && start > s.top().second){
            s.pop();
        }
        if (!s.empty() && s.top().second < end){
            cout << -1 << endl;
            return 0;
        }
        s.push({start,end});
        visited.insert(c[i]);
        int x = s.size();
        ans = max(ans,x);
    }
    
    cout << ans << endl;

    return 0;
}
