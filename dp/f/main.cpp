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
    string s, t;
    cin >> s >> t;
    mi n = s.size();
    mi m = t.size();
    vvmi dp(n, vmi(m, 0));
    mi ans_len = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            if (i == 0) {
                if (s.at(0) == t.at(j)) {
                    // cout << i << " " << j << " " << s.at(i) << endl;
                    dp.at(0).at(j) = 1;
                }
                chmax(ans_len, dp.at(0).at(j));
                continue;
            }
            if (s.at(i) == t.at(j)) {
                if (j == 0) {
                    // cout << i << " " << j << " " << s.at(i) << endl;
                    dp.at(i).at(j) = 1;
                } else {
                    // cout << i << " " << j << " " << s.at(i) << " " << dp.at(i - 1).at(j - 1) << endl;
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
                }
            } else {
                if (j == 0) {
                    // cout << i << " " << j << " " << s.at(i) << endl;
                    dp.at(i).at(j) = max((mi)0, dp.at(i - 1).at(j));
                } else {
                    // cout << i << " " << j << " " << s.at(i) << " " << dp.at(i - 1).at(j - 1) << endl;
                    dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
                }
            }
            chmax(ans_len, dp.at(i).at(j));
        }
    }
    cout << ans_len << endl;
    string ans(ans_len, ' ');
    ans_len--;
    n--;
    m--;
    while (ans_len >= 0) {
        if (s.at(n) == t.at(m)) {
            ans.at(ans_len) = s.at(n);
            n--;
            m--;
            ans_len--;
        } else if (dp.at(n).at(m) == dp.at(n - 1).at(m)) {
            n--;
        } else {
            m--;
        }
    }
    cout << ans << endl;
}
