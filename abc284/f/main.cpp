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
void naive(std::string const& p, std::string const& t)
{
    const int n = t.size();
    const int m = p.size();

    if (n == 0 || m == 0) {
        return;
    }

    int i = 0;
    while (i <= n - m) {
        int j = 0;
        while (j < m && p[j] == t[i + j])
            ++j;
        if (j == m) {
            std::cout << i << std::endl;
        }
        ++i;
    }
}
int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    string t;
    cin >> t;
    // vector<int_fast8_t> t(2 * n);
    // rep(i, 2 * n)
    // {
    //     char c;
    //     cin >> c;
    //     t.at(i) = c - 'a';
    // }
    // cout << t << endl;
    // naive("abcde", "bcde");
    rep(i, n)
    {
        char s1 = i == 0 ? t.at(n) : t.at(0);
        char g1 = i == n - 1 ? t.at(n - 1) : t.at(2 * n - 1);
        char s2 = t.at(2 * n - 1 - i);
        char g2 = t.at(n - i - 1);
        cout << s1 << g1 << s2 << g2 << endl;
        if (s1 == s2 && g1 == g2) {
            cout << i << endl;
            // return 0;
        }
    }
}
