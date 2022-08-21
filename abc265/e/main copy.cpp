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
using modi = modint998244353;
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
    vector<modint> factorial(n + 1);
    factorial[0] = 1;
    rep(i, n)
        factorial[i + 1]
        = factorial[i] * (i + 1);
    mi a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    modi ans = 0;
    modi three = 3;
    ans = three.pow(n);
    // vmi cannot_move_x(m);
    // vmi cannot_move_y(n);
    // rep(i, m)
    // {
    //     cin >> cannot_move_x.at(i) >> cannot_move_y.at(i);
    // }
    set<pair<mi, mi>> cannot_move;
    rep(i, m)
    {
        mi x, y;
        cin >> x >> y;
        cannot_move.insert({ x, y });
    }
    vmi memoi;
    vmi memoj;
    vmi memok;
    rep(i, n + 1)
    {
        rep(j, n - i + 1)
        {
            rep(k, n - i - j + 1)
            {
                mi x = i * a + j * c + k * e;
                mi y = i * b + j * d + k * f;
                mi kaisu = i + j + k;
                // cout << x << " " << y << " " << kaisu << " " << i << " " << j << " " << k << endl;
                if (cannot_move.count({ x, y })) {
                    memoi.push_back(i);
                    memoj.push_back(j);
                    memok.push_back(k);
                    modint ncr = factorial[kaisu] / factorial.at(i) / factorial.at(kaisu - i);
                    mi nokori = kaisu - i;
                    modint ncr2 = factorial[nokori] / factorial.at(nokori) / factorial.at(kaisu - nokori);
                    modint aaa = ncr * ncr2;
                    // continue;
                    // cout << x << " " << y << " " << kaisu << " " << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    cout << ans.val() << endl;
    vector<vvmi> a(n + 1, vvmi())
}
