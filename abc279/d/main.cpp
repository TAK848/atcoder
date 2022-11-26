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
double func(double a, double b, double count)
{
    return (double)(b * count) + ((double)a / sqrt(count + 1));
}
int main()
{
    __SPEED_UP__
    double a, b;
    cin >> a >> b;
    // cout << setprecision(11);
    double ok = 1e-8;
    // 三分探索
    mi left = 0, right = 1e18;
    while (right - left > 1) {
        mi mid1 = (left * 2 + right) / 3;
        mi mid2 = (left + right * 2) / 3;
        double y1 = func(a, b, left);
        double y2 = func(a, b, mid1);
        double y3 = func(a, b, mid2);
        double y4 = func(a, b, right);
        // cout << left << " " << mid1 << " " << mid2 << " " << right << " " << y1 << " " << y2 << " " << y3 << " " << y4 << endl;

        if (y2 < y3 && y3 < y4) {
            right = mid2;
        } else if (y1 > y2 && y2 > y3) {
            left = mid1;
        } else {
            left = mid1;
            right = mid2;
        }
    }
    // cout << a << " " << b << " " << left << endl;
    // cout << func(a, b, left) << endl;
    printf("%.10f\n", min(func(a, b, left), func(a, b, right)));
}
