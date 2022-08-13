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

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vvmi b(n);
    string c;
    cin >> c;
    rep(i, n)
    {
        if (c.at(i) == 'B') {
            b.at(n - 1).push_back(0);
        } else if (c.at(i) == 'R') {
            b.at(n - 1).push_back(1);
        } else if (c.at(i) == 'W') {
            b.at(n - 1).push_back(2);
        }
    }
    mi i = n - 1;
    mi minusv = 27 * 27 * 27 * 27;
    while (i >= 0) {
        mi next;
        if (i == 0) {
            cout << (b.at(0).at(0) == 0 ? "B" : (b.at(0).at(0) == 1 ? "R" : "W")) << endl;
            break;
        }
        while (true) {
            next = i - minusv;
            if (next >= 0) {
                break;
            } else {
                minusv /= 3;
            }
        }
        rep(j, i - minusv + 1)
        {
            mi l = b.at(i).at(j), r = b.at(i).at(j + minusv);
            if (l == r) {
                b.at(i - minusv).push_back(l);
            } else {
                b.at(i - minusv).push_back(3 - l - r);
            }
        }
        // i -= 3;
        // cout << i << " " << next << " " << minusv << endl;
        i = next;
    }
    // for (mi j = i; j > 0; j--) {
    //     // cout << j << endl;
    //     rep(k, j)
    //     {
    //         mi l = b.at(j).at(k), r = b.at(j).at(k + 1);
    //         if (l == r) {
    //             b.at(j - 1).push_back(l);
    //         } else {
    //             b.at(j - 1).push_back(3 - l - r);
    //         }
    //     }
    // }
    // // cout << b.at(0).at(0) << endl
    // //      << endl;
    // cout << (b.at(0).at(0) == 0 ? "B" : (b.at(0).at(0) == 1 ? "R" : "W")) << endl;
    // cout << b.at(1).at(0) << " " << b.at(1).at(1) << endl;
    // forall(it, b)
    // {
    //     // forall(it2, it) cout << it2 << " ";
    //     forall(it2, it) cout << (it2 == 0 ? 'B' : (it2 == 1 ? 'R' : 'W')) << "";
    //     cout << endl;
    // }
}
