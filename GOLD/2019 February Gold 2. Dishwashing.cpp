#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define all(x) (x).begin(), (x).end()

vi p;

bool ok(int e) {
    deque<int> notWashed(p.begin(), p.begin() + e + 1);
    sort(all(notWashed));
    deque<vi> soap;

    for (int i = 0; i <= e; i++) {
        int plate = p[i];

        int pos = -1;
        int dq_size = soap.size();
        for (int z = e + 1; z > 0; z /= 2) {
            while (pos + z < dq_size && soap[pos + z].back() <= plate) 
                pos += z;
        }
        pos++;
        if (pos == dq_size) soap.push_back({plate});
        else soap[pos].push_back(plate);

        while (!soap.empty() && soap.front().back() == notWashed.front()) {
            notWashed.pop_front();
            soap.front().pop_back();
            if (soap.front().empty()) soap.pop_front();
        }
    }
    return notWashed.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    p.resize(n);
    for (int &x : p) cin >> x;

    int end = -1;
    for (int b = n; b > 0; b /= 2) {
        while (end + b < n && ok(end + b)) end += b;
    }
    end++;

    cout << end << "\n";
}
