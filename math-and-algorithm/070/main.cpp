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
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// // aよりもbが大きいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmax(T& a, const T& b)
// {
//     if (a < b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b; // aをbで更新
        return true;
    }
    return false;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n, k;
    cin >> n >> k;
    vector<pair<mi, mi>> p(n);
    set<mi> xl, yl;
    rep(i, n)
    {
        cin >> p.at(i).first >> p.at(i).second;
        xl.insert(p.at(i).first);
        yl.insert(p.at(i).second);
    }
    mi ans = INT64_MAX;
    for (auto x1 : xl) {
        for (auto x2 : xl) {
            if (x1 > x2)
                continue;
            for (auto y1 : yl) {
                for (auto y2 : yl) {
                    if (y1 > y2)
                        continue;
                    pair<mi, mi> xy1(x1, y1);
                    pair<mi, mi> xy2(x2, y2);
                    mi count = 0;
                    // cout << "ccccc" << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
                    for (auto xy : p) {
                        mi x = xy.first;
                        mi y = xy.second;
                        if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
                            // continue;
                            // cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << x << " " << y << endl;
                            count++;
                        }
                    }
                    if (count >= k) {
                        // cout << "!!!!!" << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
                        chmin(ans, abs(x1 - x2) * abs(y1 - y2));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
