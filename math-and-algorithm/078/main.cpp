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
    mi n, m;
    cin >> n >> m;
    vvmi g(n, vmi());
    rep(i, m)
    {
        mi a, b;
        cin >> a >> b;
        g.at(a - 1).push_back(b - 1);
        g.at(b - 1).push_back(a - 1);
    }
    vmi dist = vmi(n, -1);
    queue<mi> que;
    que.push(0);
    dist.at(0) = 0;
    while (!que.empty()) {
        mi u = que.front();
        que.pop();
        rep(i, g.at(u).size())
        {
            mi v = g.at(u).at(i);
            if (dist.at(v) == -1) {
                dist.at(v) = dist.at(u) + 1;
                que.push(v);
            }
        }
    }
    rep(i, n)
    {
        cout << (dist.at(i) == -1 ? 120 : min(dist.at(i), (mi)120)) << '\n';
    }
}
