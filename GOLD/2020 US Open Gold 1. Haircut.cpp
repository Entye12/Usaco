#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int m,n;
vll tree;

int padding(int n){
    int p = 1;
    while (p < n) p <<= 1;
    return p;
}

ll sumQ(int l, int r){
    ll res = 0;
    for (l += n-1, r += n-1; l <= r; l >>= 1, r >>= 1){
        if (l&1) res += tree[l++];
        if (!(r&1)) res += tree[r--];
    }
    return res;
}

void pointUpdate(int i, int u){
    for (tree[i += n-1] += u; i > 1; i >>= 1){
        tree[i >> 1] = tree[i] + tree[i^1];
    } 
}

void build() {
    for (int i = n - 1; i > 0; i--)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m;
    vector<vi> idx(m+1);

    for (int i=1;i<=m;i++){
        int x;
        cin >> x;
        idx[x].push_back(i);
    }

    n = padding(m);
    tree.assign(2 * n, 1);
    build();

    ll ans = 0;
    cout << ans << '\n';
    
    for (int j=1;j<m;j++){
        if (!idx[j-1].empty()){
            for (int i : idx[j-1]){
                ans += sumQ(1,i) - 1;
                pointUpdate(i,-1);
            }
        } 
        cout << ans << '\n'; 
    }

    return 0;
}
