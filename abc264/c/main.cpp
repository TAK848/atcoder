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

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi h1, w1;
    cin >> h1 >> w1;
    vvmi a(h1, vmi(w1));
    rep(i, h1) rep(j, w1) cin >> a.at(i).at(j);
    mi h2, w2;
    cin >> h2 >> w2;
    vvmi b(h2, vmi(w2));
    rep(i, h2) rep(j, w2) cin >> b.at(i).at(j);
    bool ans = false;
    rep(i, 1 << h1)
    {
        bitset<10> hbs(i);
        rep(j, 1 << w1)
        {
            bitset<10> wbs(j);
            bool flag = true;
            // check a equal b
            if (h2 != hbs.count() || w2 != wbs.count()) {
                flag = false;
                continue;
            }
            mi bh = 0;
            rep(k, h1)
            {
                if (!hbs.test(k)) {
                    // flag = false;
                    continue;
                }
                mi bw = 0;
                rep(l, w1)
                {
                    if (!wbs.test(l)) {
                        // flag = false;
                        continue;
                    }
                    // cout << i << " " << j << " " << k << " " << l << " " << a.at(k).at(l) << " " << b.at(bh).at(bw) << endl;
                    // if (hbs[k] && wbs[l]) {
                    if (a.at(k).at(l) != b.at(bh).at(bw)) {
                        // cout << "No" << endl;
                        // return 0;
                        flag = false;
                        continue;
                    }
                    // }
                    bw++;
                }
                bh++;
            }
            if (flag) {
                // ans = true;
                // break;
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
