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
#define forall(i, v) for (auto& i : v)
#define forallpair(i, j, v) for (auto& [i, j] : v)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
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

// #define endl '\n'
vmi dp;
vb visited;
vvmi g;
void dfs(mi pos)
{
    visited.at(pos) = true;
    dp.at(pos) = 1;
    forall(i, g.at(pos))
    {
        if (!visited.at(i)) {
            dfs(i);
            dp.at(pos) += dp.at(i);
        }
    }
}
int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    dp.resize(n);
    visited.resize(n);
    g.resize(n);
    rep(i, n - 1)
    {
        mi a, b;
        cin >> a >> b;
        a--;
        b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }
    dfs(0);
    mi ans = 0;
    rep2(i, 1, n) ans += dp.at(i) * (n - dp.at(i));
    cout << ans << '\n';
}
