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

// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
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
    mi n;
    cin >> n;
    vmi a(n), b(n), c(n);
    rep(i, n) cin >> a.at(i) >> b.at(i) >> c.at(i);
    double ans = 0;
    cout << fixed << setprecision(12);
    rep(i, n) rep2(j, i + 1, n)
    {
        // cout << i << " " << j << endl;
        if (a.at(i) * b.at(j) == a.at(j) * b.at(i)) {
            continue;
        }
        double x = (double)(c.at(i) * b.at(j) - b.at(i) * c.at(j)) / (double)(a.at(i) * b.at(j) - b.at(i) * a.at(j));
        double y = (double)(c.at(i) * a.at(j) - a.at(i) * c.at(j)) / (double)(b.at(i) * a.at(j) - a.at(i) * b.at(j));
        // cout << x << " " << y << " " << x + y << endl;
        bool flag = true;
        rep(i, n)
        {
            if (a.at(i) * x + b.at(i) * y > c.at(i)) {
                flag = false;
                break;
            }
        }
        if (flag)
            chmax(ans, x + y);
    }
    cout << ans << endl;
}
