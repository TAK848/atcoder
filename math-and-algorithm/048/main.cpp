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
    mi k;
    cin >> k;
    vector<vector<pair<mi, mi>>> g(k); //[今の頂点]<次の頂点, 次の距離>
    rep(i, k)
    {
        rep(j, 10)
        {
            if (i == 0 && j == 0)
                continue;
            g.at(i).push_back(make_pair((i * 10 + j) % k, j));
        }
    }
    vmi dist(k, INT32_MAX);
    vmi used(k, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que; //<今の重み, 次の場所>
    que.push(make_pair(0, 0));
    while (!que.empty()) {
        auto pos = que.top().second;
        que.pop();
        if (used[pos])
            continue;
        used[pos] = true;
        // dist[p.second] = p.first;
        for (auto i : g[pos]) {
            mi to = i.first, cost = dist.at(pos) + i.second;
            if (pos == 0)
                cost = i.second;
            if (dist.at(to) > cost) {
                dist.at(to) = cost;
                que.push(make_pair(cost, to));
            }
            // que.push(make_pair(p.first + cost, next));
        }
    }
    cout << dist.front() << '\n';
}
