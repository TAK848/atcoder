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
mi check(string s, mi start)
{
    mi n = s.size();
    mi count = 0;
    rep(i, (n + 1) / 2)
    {
        // if (s.at(i) != s.at(n - i - 1)) {
        //     count++;
        // }
        if (s.at((i + start) % n) != s.at((n - i - 1 + start) % n)) {
            count++;
        }
        // cout << i << " " << (i + start) / n << " " << (n - i - 1 + start) / n << endl;
    }
    return count;
}

int main()
{
    __SPEED_UP__
    mi n, a, b;
    cin >> n >> a >> b;
    mi ans = INT64_MAX;
    string s;
    cin >> s;
    rep(i, n)
    {
        // cout << check(s, i) << endl;
        // rep(j, n)
        // {
        //     // cout << check(s, j) << endl;
        //     chmin(ans, check(s, i));
        // }
        chmin(ans, i * a + b * check(s, i));
    }
    cout << ans << endl;
}
