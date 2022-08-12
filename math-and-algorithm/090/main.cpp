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
// // aよりもbが小さいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmin(T& a, const T& b)
// {
//     if (a > b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }

// #define endl '\n'
set<mi> fm_cand;
mi product(mi m)
{
    if (m == 0) {
        return 0;
    } else {
        mi ans = 1;
        while (m >= 1) {
            ans *= m % 10;
            m /= 10;
        }
        return ans;
    }
}
void func(mi digit, mi m)
{
    if (digit == 11) {
        fm_cand.insert(product(m));
        return;
    }
    mi min_value = m % 10;
    rep2(i, min_value, 10)
    {
        func(digit + 1, m * 10 + i);
    }
}
int main()
{
    __SPEED_UP__
    func(0, 0);
    mi n, b;
    cin >> n >> b;
    mi ans = 0;
    for (auto fm : fm_cand) {
        mi m = fm + b;
        mi prod_m = product(m);
        if (m - prod_m == b && m <= n) {
            ans++;
        }
    }
    cout << ans << '\n';
}
