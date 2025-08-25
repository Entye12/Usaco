#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using vi = vector<int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    
    int n,g;
    cin >> n >> g;
    vector<vi> operations(n+1,vi(3,0));
    unordered_map<int,int> cur;
    map<int,int> cnt;
    
    cnt[g] = n+10;
    
    for (int i=1;i<=n;i++){
        cin >> operations[i][0] >> operations[i][1] >> operations[i][2];
        int id = operations[i][1];
        cur[id] = g;
    }
    sort(all(operations));
    
    for (int i=1;i<=n;i++){
        int id = operations[i][1];
        int old = cur[id];
        int u = operations[i][2];
        int next = old + u;
        
        int oldMax = max(g,cnt.rbegin()->first);
        bool cowWasTop = (old == oldMax);
        int oldCnt = cnt[oldMax];
        
        cnt[old]--;
        if (cnt[old] == 0) cnt.erase(old);
        cnt[next]++;
        cur[id] = next;
        
        int newMax = max(g,cnt.rbegin()->first);
        bool cowInTop = (next == newMax);
        int newCnt = cnt[newMax];
        
        if (cowInTop != cowWasTop) ans++;
        else if (cowInTop && newMax != oldMax && (oldCnt != 1 || newCnt != 1)) ans++;
    
    }
    
    cout << ans << endl;
    return 0;
}
