#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vd = vector<double>;
using vvd = vector<vd>;
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
#define forall(i, v) for (auto& i : v)
#define forallpair(i, j, v) for (auto& [i, j] : v)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// aよりもbが大きいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
// aよりもbが小さいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <typename T>
inline istream& operator>>(istream& is, vector<T>& vec)
{
    for (T& x : vec)
        is >> x;
    return is;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n, m;
    cin >> n >> m;
    vmi a(n);
    cin >> a;
    vector<set<mi>> g(n);
    rep(i, m)
    {
        mi x, y;
        cin >> x >> y;
        x--;
        y--;
        if (x > y)
            swap(x, y);
        g.at(y).insert(x);
    }
    dsu d(n);
    vmi dp(n);
    dp.at(0) = 0;
    rep2(i, 1, n)
    {
        mi count = 0;
        forall(j, g.at(i))
        {
            d.merge(i, j);
            // count += a.at(j);
            cout << i << " " << j << " " << count << endl;
        }
        forall(j, d.groups().at(i))
        {
            count += a.at(j);
        }
        dp.at(i) = dp.at(i - 1) + min(a.at(i), count);
    }
    cout << dp.at(n - 1) << endl;
}
