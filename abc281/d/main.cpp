#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vvvmi = vector<vvmi>;
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
    mi n, k, d;
    cin >> n >> k >> d;
    vmi a(n);
    cin >> a;
    // partial sum(K個の和)
    // dp
    // dp[i][j][k] := i番目までの数列の中からj個選んだときのkの倍数の最大値
    vvvmi dp(n + 1, vvmi(k + 1, vmi(d, -1)));
    dp[0][0][0] = 0;
    rep2(i, 1, n + 1)
    {
        mi nowa = a[i - 1];
        rep(j, k + 1) rep(l, d)
        {
            if (dp[i - 1][j][l] == -1)
                continue;
            chmax(dp[i][j][l], dp[i - 1][j][l]);
            if (j + 1 <= k)
                chmax(dp[i][j + 1][(l + nowa) % d], dp[i - 1][j][l] + nowa);
        }
    }
    cout << dp[n][k][0] << endl;
}
