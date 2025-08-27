#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) (x).begin(),(x).end()

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,B;
    cin >> N >> B;

    multiset<int> dist{0};
    set<int> idx{0,N+1};
    
    vector<vi> tiles(N+1,{0,0});
    for (int i=1;i<=N;i++){
        cin >> tiles[i][0];
        tiles[i][1] = i;
        idx.insert(i);
        dist.insert(0);
    }
    sort(all(tiles));

    vi max_di(N+1,0);
    
    for (int i=N;i>0;i--){
        int j = tiles[i][1];
        auto it = idx.find(j);
        int left_d = *it - *prev(it) - 1;
        int right_d = *next(it) - *it - 1;
        int merged_d = *next(it) - *prev(it) - 1;

        idx.erase(j);
        dist.insert(merged_d);
        dist.erase(dist.find(left_d));
        dist.erase(dist.find(right_d));
        max_di[j] = *prev(dist.end());
    }

    for (int i=1;i<=B;i++){
        int s,d;
        cin >> s >> d;

        auto it = upper_bound(all(tiles), vi{s,N+2});
        if (it == tiles.end()){
            cout << 1 << '\n';
        }
        else {
            int j = (*it)[1];
            if (max_di[j] >= d) cout << 0 << '\n';
            else cout << 1 << '\n';
        }
    }
    return 0;
}
