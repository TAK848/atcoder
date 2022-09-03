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
    string s;
    cin >> s;
    if (s.at(0) == '1') {
        cout << "No\n";
        return 0;
    }
    vmi c(7, 0);
    if (s.at(6) == '0')
        c.at(0) = 1;
    if (s.at(3) == '0')
        c.at(1) = 1;
    if (s.at(1) == '0' && s.at(7) == '0') {
        c.at(2) = 1;
    } else if (!(s.at(1) == '1' && s.at(7) == '1')) {
        c.at(2) = 2;
    }
    if (s.at(4) == '0') {
        c.at(3) = 1;
    } else {
        c.at(3) = 2;
    }
    if (s.at(2) == '0' && s.at(8) == '0') {
        c.at(4) = 1;
    } else if (!(s.at(2) == '1' && s.at(8) == '1')) {
        c.at(4) = 2;
    }
    if (s.at(5) == '0')
        c.at(5) = 1;
    if (s.at(9) == '0')
        c.at(6) = 1;
    //倒れてると1
    // bool flag = false;
    mi flagstep = 0;
    rep(i, 7)
    {
        // cout << c.at(i) << " " << flagstep << endl;
        if (flagstep == 0) {
            if (c.at(i) != 1) {
                flagstep = 1;
            }
        } else if (flagstep == 1) {
            if (c.at(i) == 1)
                flagstep = 2;
        } else {
            if (c.at(i) != 1) {
                cout << "Yes\n";
                return 0;
            }
        }

        // if (c.at(i)) {
        //     if (flag) {
        //         cout << "No\n";
        //         return 0;
        //     }
        //     flag = true;
        // } else {
        //     flag = false;
        // }
    }
    cout << "No\n";
}
