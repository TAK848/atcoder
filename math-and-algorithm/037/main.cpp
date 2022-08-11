#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)
#define repstep(i, n, step) for (mi i = (mi)(n); i < (mi)(n) + (mi)(step); i++)
#define rep2(i, m, n) for (mi i = (mi)(m); i < (mi)(n); i++)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// // aよりもbが大きいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmax(T& a, const T& b)
// {
//     if (a < b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }
// // aよりもbが小さいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmin(T& a, const T& b)
// {
//     if (a > b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    mi x12, y12, x13, y13, x14, y14, x31, y31, x32, y32, x34, y34;
    x12 = x2 - x1;
    y12 = y2 - y1;
    x13 = x3 - x1;
    y13 = y3 - y1;
    x14 = x4 - x1;
    y14 = y4 - y1;
    x31 = x1 - x3;
    y31 = y1 - y3;
    x32 = x2 - x3;
    y32 = y2 - y3;
    x34 = x4 - x3;
    y34 = y4 - y3;
    mi s1 = x12 * y13 - x13 * y12;
    mi t1 = x12 * y14 - x14 * y12;
    mi s2 = x34 * y31 - x31 * y34;
    mi t2 = x34 * y32 - x32 * y34;
    // cout << s1 << " " << t1 << " " << s2 << " " << t2 << endl;
    if ((s1 == 0 && t1 == 0 && s2 == 0 && t2 == 0)) {
        mi a, b, c, d;
        if (x1 == x2 && x1 == x3 && x1 == x4) {
            a = y1;
            b = y2;
            c = y3;
            d = y4;
        } else {
            a = x1;
            b = x2;
            c = x3;
            d = x4;
        }
        if (a > b) {
            swap(a, b);
        }
        if (c > d) {
            swap(c, d);
        }
        if ((max(a, c) <= min(b, d))) {
            cout << "Yes" << '\n';
            return 0;
        } else {
            cout << "No" << '\n';
            return 0;
        }
    } else if (((s1 >= 0 && t1 <= 0) || (s1 <= 0 && t1 >= 0)) && ((s2 >= 0 && t2 <= 0) || (s2 <= 0 && t2 >= 0))) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    // cout << endl;
}
