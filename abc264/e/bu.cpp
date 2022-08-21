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
    mi n, m, e;
    cin >> n >> m >> e;
    vector<set<mi>> g(n);
    vector<set<mi>> powerline(n);
    vector<pair<mi, mi>> edges;
    mi livecount = 0;
    vb liveplace = vb(n, false);
    rep(i, e)
    {
        mi u, v;
        cin >> u >> v;
        u--;
        v--;
        edges.emplace_back(u, v);
        if (u >= n) {
            continue;
        } else if (u < n && v < n) {
            g.at(u).insert(v);
            g.at(v).insert(u);
        } else {
            powerline.at(u).insert(i);
            if (powerline.at(u).size() == 1) {
                livecount++;
                liveplace.at(u) = true;
            }
        }
    }
    mi q;
    cin >> q;

    rep(i, q)
    {
        mi x;
        cin >> x;
        x--;
        auto [u, v] = edges.at(x);
        if (u >= n) {
            // 発電所同士は無視
        } else if (u < n && v < n) {
            // 都市同士なら
            g.at(u).erase(v);
            g.at(v).erase(u);
            if (powerline.at(u).size() == 0) {
                livecount--;
                // forall()
                liveplace.at(u) = false;
            }
        } else {
            // powerline.at(u).erase(x);
            if (powerline.at(u).size() == 1) {
                powerline.at(u).erase(x);
                // livecount--;
                // liveplace.at(u) = false;
                bool flag = false;
                forall(w, g.at(u))
                {
                    if (liveplace.at(w)) {
                        if (g.at(w).size() == 0 && powerline.at(w).size() == 0) {
                            livecount--;
                            liveplace.at(w) = false;
                            // flag = true;
                        } else {
                            flag = true;
                        }
                        // flag = true;
                        // break;
                    }
                    // powerline.at(v).erase(x);
                    // if (powerline.at(v).size() == 0) {
                    //     // livecount--;
                    //     liveplace.at(v) = false;
                    // }
                }
                if (!flag) {
                    livecount--;
                    liveplace.at(u) = false;
                }
            }
        }
        cout << livecount << '\n';
    }
}
