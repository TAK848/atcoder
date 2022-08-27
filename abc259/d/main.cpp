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
    mi n;
    cin >> n;
    mi sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vmi x(n), y(n), r(n);
    rep(i, n) cin >> x.at(i) >> y.at(i) >> r.at(i);
    dsu d(n);
    mi start = -1;
    mi end = -1;
    rep(i, n)
    {
        mi s_dist_squ = (sx - x.at(i)) * (sx - x.at(i)) + (sy - y.at(i)) * (sy - y.at(i));
        mi t_dist_squ = (tx - x.at(i)) * (tx - x.at(i)) + (ty - y.at(i)) * (ty - y.at(i));
        if (s_dist_squ == r.at(i) * r.at(i)) {
            start = i;
        }
        if (t_dist_squ == r.at(i) * r.at(i)) {
            end = i;
        }
        rep(j, i)
        {
            mi dist_squ = (x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j));
            mi plus_squ = (r.at(i) + r.at(j)) * (r.at(i) + r.at(j));
            mi minus_squ = abs(r.at(i) - r.at(j)) * abs(r.at(i) - r.at(j));
            if (minus_squ <= dist_squ && dist_squ <= plus_squ) {
                d.merge(i, j);
            }
        }
    }
    cout << YesNo(d.same(start, end)) << endl;
}
