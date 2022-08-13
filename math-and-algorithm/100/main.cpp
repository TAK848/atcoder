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

vvd multiplication(vvd& a, vvd& b)
{
    mi size = a.size();
    vvd c(size, vd(size, 0));
    rep(i, size)
    {
        rep(j, size)
        {
            rep(k, size)
            {
                c.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
            }
        }
    }
    return c;
}
vvd power(vvd& a, mi n)
{
    vvd p = a, q;
    bitset<64> b(n);
    bool flag = false;
    rep(i, b.size())
    {
        if (b[i]) {
            if (flag) {
                q = multiplication(q, p);
            } else {
                q = p;
                flag = true;
            }
        }
        p = multiplication(p, p);
    }
    return q;
}

int main()
{
    __SPEED_UP__
    mi q;
    cin >> q;
    cout << fixed << setprecision(8);
    rep(i, q)
    {
        double x, y, z, t;
        cin >> x >> y >> z >> t;
        vvd a = {
            { 1 - x, y, 0 },
            { 0, 1 - y, z },
            { x, 0, 1 - z },
        };
        vvd b = power(a, t);
        cout << b.at(0).at(0) + b.at(0).at(1) + b.at(0).at(2) << ' ' << b.at(1).at(0) + b.at(1).at(1) + b.at(1).at(2) << ' ' << b.at(2).at(0) + b.at(2).at(1) + b.at(2).at(2) << '\n';
    }
}
