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
    vector<pair<mi, mi>> a(n);
    rep(i, n)
    {
        mi x;
        cin >> x;
        a.at(i) = make_pair(x, 0);
    }
    mi step = 0;
    mi newallvalue = -1;
    mi q;
    cin >> q;
    rep(_, q)
    {
        mi query;
        cin >> query;
        // cout << query << endl;
        if (query == 1) {
            mi x;
            cin >> x;
            step++;
            newallvalue = x;
            // a = vector<mi>(n, x);
        } else if (query == 2) {
            mi i, x;
            cin >> i >> x;
            i--;
            if (step == 0) {
                a.at(i).first += x;
            } else if (a.at(i).second < step) {
                a.at(i).first = x;
                a.at(i).second = step;
            } else {
                a.at(i).first += x;
            }
            //
        } else {
            mi i;
            cin >> i;
            i--;
            if (step == 0) {
                cout << a.at(i).first << '\n';
            } else {
                if (a.at(i).second < step) {
                    cout << newallvalue << '\n';
                } else {
                    cout << newallvalue + a.at(i).first << '\n';
                }
            }
            // cout << a.at(i) << '\n';
        }
    }
}
