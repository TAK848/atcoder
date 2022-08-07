#include <bits/stdc++.h>
using namespace std;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
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
    mi n, l, r;
    cin >> n >> l >> r;
    vmi a(n);
    vmi leftsum(n);
    vmi leftsummin(n);
    vmi rightsummin(n + 1);
    rightsummin.at(n) = 0;
    rep(i, n)
    {
        cin >> a.at(i);
        leftsum.at(i) = (i == 0 ? a.at(i) : leftsum.at(i - 1) + a.at(i));
        leftsummin.at(i) = min(leftsum.at(i), l * (i + 1));
        if (i != 0) {
            leftsummin.at(i) = min(leftsummin.at(i), leftsummin.at(i - 1) + a.at(i));
        }
    }

    vmi rightsum(n);
    rep(i, n)
    {
        rightsum.at(n - i - 1) = (i == 0 ? a.at(n - i - 1) : rightsum.at(n - i) + a.at(n - i - 1));
        rightsummin.at(n - i - 1) = min(rightsum.at(n - i - 1), r * (i + 1));
    }
    mi mmm = rightsummin.at(0);
    rep(i, n)
    {
        mmm = min(mmm, leftsummin.at(i) + rightsummin.at(i + 1));
    }
    cout << mmm << "\n";
}
