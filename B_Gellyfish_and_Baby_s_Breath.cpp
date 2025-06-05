#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

constexpr int MOD = 998244353;
vector<int> pow2_vec = {1};  // start with 2^0 = 1

void extend_pow2(int e) {
    while ((int)pow2_vec.size() <= e) {
        int last = pow2_vec.back();
        pow2_vec.push_back((2LL * last) % MOD);
    }
}

void solve() {
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    vector<int> pos_p(n), pos_q(n), unlock(n);

    int max_val = 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos_p[p[i]] = i;
        max_val = max(max_val, p[i]);
    }

    for (int i = 0; i < n; ++i) {
        cin >> q[i];
        pos_q[q[i]] = i;
        max_val = max(max_val, q[i]);
    }

    extend_pow2(max_val);

    for (int v = 0; v < n; ++v)
        unlock[v] = min(pos_p[v], pos_q[v]);

    priority_queue<int> heap;
    vector<int> r(n);
    vector<vector<int>> to_unlock(n);  // unlock[v] == i ⇒ store v into to_unlock[i]

    for (int v = 0; v < n; ++v)
        to_unlock[unlock[v]].push_back(v);

    for (int i = 0; i < n; ++i) {
        for (int v : to_unlock[i]) {
            heap.push(v);
        }

        int M = heap.top();  // max unlocked value
        int val;

        if (pos_p[M] <= i) {
            int j = pos_p[M];
            int k = i - j;
            val = (pow2_vec[M] + pow2_vec[q[k]]) % MOD;
        } else {
            int k = pos_q[M];
            int j = i - k;
            val = (pow2_vec[M] + pow2_vec[p[j]]) % MOD;
        }

        r[i] = val;
    }

    for (int i = 0; i < n; ++i)
        cout << r[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
