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
    mi n, x, y;
    cin >> n >> x >> y;
    mi s;
    cin >> s;
    x -= s;
    mi xn = (n + 1) / 2 - 1;
    mi yn = n / 2;
    // n--;
    vmi xa(xn);
    vmi ya(yn);
    rep(i, n / 2)
    {
        mi xx, yy;
        cin >> xx;
        ya.at(i) = xx;
        if (xn - 1 >= i) {
            cin >> yy;
            xa.at(i) = yy;
        }
    }
    x = abs(x);
    y = abs(y);
    // cout << x << " ";
    // cout << y << endl;
    // cout << xa << endl;
    // cout << ya << endl;
    mi sumxa = accumulate(all(xa), 0LL);
    mi sumya = accumulate(all(ya), 0LL);
    if ((sumxa + x) % 2 == 1 || (sumya + y) % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    mi targetx = (sumxa + x) / 2;
    mi targety = (sumya + y) / 2;
    vvb dpx(xn + 1, vb(targetx + 1, false));
    vvb dpy(yn + 1, vb(targety + 1, false));
    dpx.at(0).at(0) = true;
    dpy.at(0).at(0) = true;
    rep(i, xn)
    {
        rep(j, targetx + 1)
        {
            if (dpx.at(i).at(j)) {
                dpx.at(i + 1).at(j) = true;
                if (j + xa.at(i) <= targetx) {
                    dpx.at(i + 1).at(j + xa.at(i)) = true;
                }
            }
        }
    }
    rep(i, yn)
    {
        rep(j, targety + 1)
        {
            if (dpy.at(i).at(j)) {
                dpy.at(i + 1).at(j) = true;
                if (j + ya.at(i) <= targety) {
                    dpy.at(i + 1).at(j + ya.at(i)) = true;
                }
            }
        }
    }
    // cout << dpx << endl;
    // cout << dpy << endl;
    cout << YesNo(dpx.at(xn).at(targetx) && dpy.at(yn).at(targety)) << endl;
}
