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

int main()
{
    __SPEED_UP__
    mi n;
    string s, t;
    cin >> n >> s >> t;
    // mi a, b, c, d;
    mi a = 0, b = 0, c = 0, d = 0;
    rep(i, n)
    {
        if (s.at(i) == '0' && t.at(i) == '0')
            a++;
        if (s.at(i) == '0' && t.at(i) == '1')
            b++;
        if (s.at(i) == '1' && t.at(i) == '0')
            c++;
        if (s.at(i) == '1' && t.at(i) == '1')
            d++;
    }
    if ((b + c) % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    // cout << "a:" << a << " b:" << b << " c:" << c << " d:" << d << endl;
    // mi bc = (b + c) / 2;
    mi bc = 0;
    mi nokori = (b + c);
    bool limiter = false;
    string ans = "";
    // cout << "nokori: " << nokori << endl;
    rep(i, n)
    {
        if (s.at(i) == '0' && t.at(i) == '0') {
            ans.append("0");
        }
        if (s.at(i) == '0' && t.at(i) == '1') {
            // if (abs(bc) <= nokori) {
            if (!limiter) {
                ans.append("0");
                bc++;
                if (abs(bc) == nokori - 1)
                    limiter = true;
            } else {
                // ans.append("1");
                if (bc > 0) {
                    ans.append("1");
                } else {
                    ans.append("0");
                }
                bc--;
            }
            nokori--;
        }
        if (s.at(i) == '1' && t.at(i) == '0') {
            // c--;
            // if (abs(bc) <= nokori) {
            if (!limiter) {
                ans.append("0");
                bc--;
                if (abs(bc) == nokori - 1)
                    limiter = true;
            } else {
                // ans.append("1");
                if (bc < 0) {
                    ans.append("1");
                } else {
                    ans.append("0");
                }
                bc++;
            }
            nokori--;
        }
        if (s.at(i) == '1' && t.at(i) == '1') {
            ans.append("0");
        }
        // cout << "bc: " << bc << " nokori: " << nokori << " limiter: " << limiter << endl;
    }
    cout << ans << endl;
    return 0;
}
