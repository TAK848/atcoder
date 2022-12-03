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
template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& vec)
{
    mi size = vec.size();
    rep(i, size) os << vec.at(i) << (i + 1 == size ? "" : " ");
    return os;
}
vector<modi> factorial;
// #define endl '\n'
modi nCr(mi n, mi r)
{
    if (n < r)
        return 0;
    if (n == r)
        return 1;
    if (r == 0)
        return 1;
    return factorial.at(n) / (factorial.at(r) * factorial.at(n - r));
}

modi modi_fast_pow(modi a, mi n)
{
    modi res = 1;
    while (n > 0) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main()
{
    __SPEED_UP__
    mi n, p;
    cin >> n >> p;
    vector<modi> dp(n + 1);
    modi kakuritsu1 = (100 - p);
    kakuritsu1 /= 100;
    modi kakuritsu2 = p;
    kakuritsu2 /= 100;
    factorial.resize(n + 1);
    factorial.at(0) = 1;
    repstep(i, 1, n) factorial.at(i) = factorial.at(i - 1) * i;
    // cout << kakuritsu1.val() << " " << kakuritsu2.val() << endl;

    // dp.at(0) = 1;
    // dp.at(1) = kakuritsu1;
    // rep2(i, 2, n + 1)
    // {
    //     dp.at(i) = dp.at(i - 1) * kakuritsu1 + dp.at(i - 2) * kakuritsu2;
    //     cout << dp.at(i).val() << endl;
    // }
    // dp.at(n) += dp.at(n - 1) * kakuritsu2;
    // cout << dp.at(n).val() << endl;
    modi ans = 0;
    rep(i, n / 2 + 1)
    {
        mi j = n - 2 * i;
        ans += nCr(i + j, i) * modi_fast_pow(kakuritsu1, j) * modi_fast_pow(kakuritsu2, i) * (i + j);
        // cout << i << "*2 " << j << "*1 " << ans.val() << endl;
        // ans += modi(2).pow(i) * modi(2).pow(n - 1 - i);
    }
    // cout << "--" << endl;
    rep(i, (n - 1) / 2 + 1)
    {
        mi j = n - 2 * i - 1;
        ans += nCr(i + j, i) * modi_fast_pow(kakuritsu1, j) * modi_fast_pow(kakuritsu2, i + 1) * (i + j + 1);
        // cout << i << "*2 " << j << "*1 " << ans.val() << endl;
    }
    // cout << modi_fast_pow(5, 0).val() << endl;
    // cout << nCr(5, 2).val() << endl;
    cout << ans.val() << endl;
}
