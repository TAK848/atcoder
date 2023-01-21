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
template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& vec)
{
    mi size = vec.size();
    rep(i, size) os << vec.at(i) << (i + 1 == size ? "" : " ");
    return os;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vmi a(n);
    cin >> a;
    vs s(n);
    cin >> s;
    vector<set<mi>> direct(n);
    rep(i, n) rep(j, n)
    {
        if (s.at(i).at(j) == 'Y') {
            direct.at(i).insert(j);
        }
    }

    vector<vector<pair<mi, mi>>> dp(n, vector<pair<mi, mi>>(n, make_pair(-1, -1)));
    rep(i, n)
    {
        dp.at(i).at(i) = make_pair(0, 0);
    }
    rep(i, n) rep(j, n)
    {
        if (direct.at(i).count(j)) {
            dp.at(i).at(j) = make_pair(1, a.at(j));
        }
    }
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                // if (direct.at(i).count(j)) {
                // if (dp.at(i).at(j).first != 1) {
                //     dp.at(i).at(j) = make_pair(1, a.at(j));
                // }
                // } else {
                //     chmax(dp.at(i).at(j).second, a.at(j));
                // }
                // }

                // if (direct.at(i).count(k) && direct.at(k).count(j)) {
                mi way1 = dp.at(i).at(k).first, val1 = dp.at(i).at(k).second;
                mi way2 = dp.at(k).at(j).first, val2 = dp.at(k).at(j).second;
                if (way1 == -1 || way2 == -1) {
                    continue;
                }
                mi way0 = dp.at(i).at(j).first, val0 = dp.at(i).at(j).second;
                mi way = way1 + way2, val = val1 + val2;
                cout << i << ' ' << k << ' ' << j << ' ' << way1 << ' ' << val1 << ' ' << way2 << ' ' << val2 << ' ' << way0 << ' ' << val0 << ' ' << way << ' ' << val << endl;
                if (way > way0) {
                    continue;
                } else if (way == way0) {
                    chmax(dp.at(i).at(j).second, val);
                } else {
                    dp.at(i).at(j) = make_pair(way, val);
                }
                cout << i << ' ' << k << ' ' << j << ' ' << way1 << ' ' << val1 << ' ' << way2 << ' ' << val2 << ' ' << way0 << ' ' << val0 << ' ' << way << ' ' << val << endl;
                // }
            }
        }
    }
    // rep(i, n)
    // {
    //     cout << i << ": ";
    //     forall(j, direct.at(i))
    //     {
    //         cout << j << ' ';
    //         if (dp.at(i).at(j).first != 1) {
    //             dp.at(i).at(j) = make_pair(1, a.at(j));
    //         } else {
    //             chmax(dp.at(i).at(j).second, a.at(j));
    //         }
    //         cout << "( ";
    //         rep(k, i + 1)
    //         {
    //             cout << k << ' ';
    //             mi way1 = dp.at(i).at(k).first, val1 = dp.at(i).at(k).second;
    //             mi way2 = dp.at(k).at(j).first, val2 = dp.at(k).at(j).second;
    //             if (way1 == -1 || way2 == -1) {
    //                 continue;
    //             }
    //             mi way0 = dp.at(i).at(j).first, val0 = dp.at(i).at(j).second;
    //             mi way = way1 + way2, val = val1 + val2;
    //             if (way > way0) {
    //                 continue;
    //             } else if (way == way0) {
    //                 chmax(dp.at(i).at(j).second, val);
    //             } else {
    //                 dp.at(i).at(j) = make_pair(way, val);
    //             }
    //             // if()
    //         }
    //         cout << ')';
    //     }
    //     cout << endl;
    // }
    rep(i, n)
    {
        rep(j, n)
        {
            cout << "(" << dp.at(i).at(j).first << ", " << dp.at(i).at(j).second << ") ";
        }
        cout << endl;
    }

    mi q;
    cin >> q;
    rep(_, q)
    {
        mi u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dp.at(u).at(v).first == -1) {
            cout << "Impossible\n";
        } else {
            cout << dp.at(u).at(v).first << ' ' << a.at(u) + dp.at(u).at(v).second << '\n';
        }
    }
}
