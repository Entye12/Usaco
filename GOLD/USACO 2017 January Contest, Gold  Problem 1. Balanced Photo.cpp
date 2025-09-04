#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using umi = unordered_map<int,int>;
using vi = vector<int>;

int n,N;
vi tree;

int padding(int x) {
    int p = 1;
    while (p < x) p <<= 1;
    return x;
}

void build(){
    for (int i=n-1;i>0;i--){
        tree[i] = min(tree[i<<1],tree[i<<1|1]);
    }
}

int getSum(int l, int r) {
    int res = 0;
    for (l += n-1, r += n-1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++];
        if (!(r & 1)) res += tree[r--];
    }
    return res;
}

void update(int idx, int val) {
    idx += n - 1;
    tree[idx] += val;
    for (idx >>= 1; idx >= 1; idx >>= 1) {
        tree[idx] = (tree[idx<<1] + tree[idx<<1|1]);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    n = padding(N);
    tree.assign(2*n,0);
    
    vi left(N+1,0),right(N+1,0),h(N+1,0),sh(N+1,0);
    
    for (int i=1;i<=N;i++){
        cin >> h[i];
        sh[i] = h[i];
    }
    sort(all(sh));
    
    umi xToIdx;
    for (int i=1;i<=N;i++) xToIdx[sh[i]] = i;
    
    for (int i=1;i<=N;i++){
        int j = xToIdx[h[i]];
        int v = getSum(j+1,n);
        left[i] = v;
        update(j,1);
    }
    
    tree.assign(2*n,0);
    for (int i=n;i>0;i--){
        int j = xToIdx[h[i]];
        int v = getSum(j+1,n);
        right[i] = v;
        update(j,1);
    }
    
    int ans = 0;
    
    for (int i=1;i<=N;i++){
        if (2*min(left[i],right[i]) < max(left[i],right[i])) ans++;
    }
    
    
    cout << ans << endl;
    
    return 0;
}
