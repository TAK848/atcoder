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
    cin >> n;
    // 二分探索
    // mi lx = 0, rx = n;
    // mi ly = 0, ry = n;
    mi l = 1, r = n;
    mi kosuu = n - 1;
    // cout << l << " " << (l + r) / 2 << " " << r << endl;
    while (true) {
        mi x = (l + r) / 2;
        // if (x == l)
        // break;
        cout << "? " << l << " " << x << " " << 1 << " " << n << endl;
        mi interectiveanswer;
        cin >> interectiveanswer;
        // scanf("%lld", &interectiveanswer);
        if (kosuu - 2 * interectiveanswer >= 0) {
            r = x;
            kosuu = interectiveanswer;
        } else {
            l = x + 1;
            kosuu = kosuu - interectiveanswer;
        }
        if (l == r)
            break;
        if (kosuu == 0) {
            break;
            // cout << "! " << l << " " << 1 << endl;
            // return 0;
        }
        // cout << l << x << r << endl;
    }
    mi x = l;
    l = 1, r = n;
    // cout << l << " " << (l + r) / 2 << " " << r << endl;
    kosuu = n - 1;
    while (true) {
        mi y = (l + r) / 2;
        // if (y == l)
        // break;
        cout << "? " << 1 << " " << n << " " << l << " " << y << endl;
        mi interectiveanswer;
        cin >> interectiveanswer;
        // scanf("%lld", &interectiveanswer);
        if (kosuu - 2 * interectiveanswer >= 0) {
            r = y;
            kosuu = interectiveanswer;
        } else {
            l = y + 1;
            kosuu = kosuu - interectiveanswer;
        }
        if (kosuu == 0)
            break;
        if (l == r)
            break;
        // cout << l << y << r << endl;
    }
    mi y = l;
    cout << "! " << x << " " << y << endl;
    return 0;
}
