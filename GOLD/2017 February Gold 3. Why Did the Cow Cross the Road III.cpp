#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using vi = vector<int>;
using usi = unordered_set<int>;

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
    n = padding(2*N);
    tree.assign(2*n,0);
    
    vi left(N+1,0),right(N+1,0),a(2*N+1,0);
    
    for (int i=1;i<=2*N;i++){
        cin >> a[i];
        if (left[a[i]] == 0) left[a[i]] = i;
        else right[a[i]] = i;
    }
    
    usi visited;
    int ans = 0;
    
    for (int i=1;i<=2*N;i++){
        int x = a[i];
        int l = left[x], r = right[x];
        if (visited.count(x)) continue;
        ans += getSum(l+1,r-1);
        visited.insert(x);
        update(r,1);
    }

    cout << ans << endl;
    
    return 0;
}
