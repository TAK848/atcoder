#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
// using modi = modint1000000007;
// using modi = modint998244353;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)
#define repstep(i, n, step) for (mi i = (mi)(n); i < (mi)(n) + (mi)(step); i++)
#define rep2(i, m, n) for (mi i = (mi)(m); i < (mi)(n); i++)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// // aよりもbが大きいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmax(T& a, const T& b)
// {
//     if (a < b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }
// // aよりもbが小さいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmin(T& a, const T& b)
// {
//     if (a > b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }

// #define endl '\n'

int main()
{
    __SPEED_UP__
    // dijkstra
    mi n, m;
    cin >> n >> m;
    vector<vector<pair<mi, mi>>> g(n); // <weight, to>
    rep(i, m)
    {
        mi a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g.at(a).emplace_back(c, b);
        g.at(b).emplace_back(c, a);
    }
    vmi dist(n, INT64_MAX);
    vb used(n, false);
    priority_queue<pair<mi, mi>, vector<pair<mi, mi>>, greater<pair<mi, mi>>> que; //<nowweight,next>
    que.emplace(0, 0);
    dist.at(0) = 0;
    while (!que.empty()) {
        mi pos = que.top().second;
        que.pop();
        if (used.at(pos)) {
            continue;
        }
        used.at(pos) = true;
        for (auto p : g.at(pos)) {
            mi next = p.second;
            mi nextweight = p.first;
            if (dist.at(next) > dist.at(pos) + nextweight) {
                dist.at(next) = dist.at(pos) + nextweight;
                que.emplace(dist.at(next), next);
            }
        }
    }
    cout << (dist.at(n - 1) == INT64_MAX ? -1 : dist.at(n - 1)) << '\n';
}
