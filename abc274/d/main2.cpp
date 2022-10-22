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
    if (n == 2) {
        mi a, b;
        cin >> a >> b;
        if (a == x && b == abs(y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    y = abs(y);
    vmi odda(n / 2, 0), evena((1 + n) / 2, 0);
    rep(i, n)
    {
        mi a;
        cin >> a;
        if (i % 2 == 0)
            evena.at(i / 2) = a;
        else
            odda.at(i / 2) = a;
    }
    mi oddsum = 0, evensum = 0;
    rep(i, n / 2) oddsum += odda.at(i);
    rep(i, (1 + n) / 2) evensum += evena.at(i);
    if ((evensum + x) % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    if ((oddsum + y) % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    // mi targetx = (evensum + x) / 2;
    mi targety = (oddsum + y) / 2;
    vvmi dpy(n / 2 + 1, vmi(targety + 1, 0));
    // vvmi dpx((1 + n) / 2 + 1, vmi(targetx + 1, 0));
    dpy.at(0).at(0) = 1;
    // dpx.at(0).at(0) = 1;

    rep(i, n / 2)
    {
        rep(j, targety + 1)
        {
            if (j - odda.at(i) >= 0)
                dpy.at(i + 1).at(j) = dpy.at(i).at(j) | dpy.at(i).at(j - odda.at(i));
            else
                dpy.at(i + 1).at(j) = dpy.at(i).at(j);
        }
    }
    // cout << dpy.at(n / 2) << endl;
    // rep(i, (1 + n) / 2)
    // {
    //     // if (i == 0) {
    //     //     continue;
    //     // }
    //     rep(j, targetx + 1)
    //     {
    //         if (j - evena.at(i) >= 0)
    //             dpx.at(i + 1).at(j) = dpx.at(i).at(j) | dpx.at(i).at(j - evena.at(i));
    //         else
    //             dpx.at(i + 1).at(j) = dpx.at(i).at(j);
    //     }
    // }
    // cout << dpx.at((1 + n) / 2) << endl;

    mi xn = (n + 1) / 2 - 1;
    x -= evena.at(0);
    evensum -= evena.at(0);
    vmi newevena(xn, 0);
    rep(i, xn) newevena.at(i) = evena.at(i + 1);
    mi targetx = (evensum + x) / 2;
    vvmi dpx(xn + 1, vmi(targetx + 1, 0));
    dpx.at(0).at(0) = 1;
    rep(i, xn)
    {
        rep(j, targetx + 1)
        {
            if (j - newevena.at(i) >= 0)
                dpx.at(i + 1).at(j) = dpx.at(i).at(j) | dpx.at(i).at(j - newevena.at(i));
            else
                dpx.at(i + 1).at(j) = dpx.at(i).at(j);
        }
    }
    // cout << "finish input" << endl;

    cout << YesNo(dpy.at(n / 2).at(targety) & dpx.at(xn - 1).at(targetx)) << endl;
    // cout << "Yes" << endl;
    // cout << evena << endl;
    // cout << odda << endl;
}
