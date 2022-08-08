#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
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
    mi n, m, q;
    cin >> n >> m >> q;
    vvmi g(n);
    rep(i, m)
    {
        mi u, v;
        cin >> u >> v;
        g.at(u - 1).push_back(v - 1);
        g.at(v - 1).push_back(u - 1);
    }
    vmi c(n);
    rep(i, n)
    {
        cin >> c.at(i);
    }
    rep(i, q)
    {
        mi op, x;
        cin >> op >> x;
        mi color = c.at(x - 1);
        cout << color << '\n';
        switch (op) {
        case 1:
            for (auto v : g.at(x - 1)) {
                c.at(v) = color;
            }
            break;
        case 2:
            mi y;
            cin >> y;
            c.at(x - 1) = y;
            break;
        }
    }
}
