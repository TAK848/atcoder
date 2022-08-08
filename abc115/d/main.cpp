#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
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
mi n, x;
vector<string> memo(51);
vmi len(51);
vmi padc(51);
mi rec(mi i, mi nowx)
{
    if (i == 0) {
        return 1;
    }
    if (nowx == 1) {
        return 0;
    } else if (nowx <= len.at(i - 1) + 1) {
        return rec(i - 1, nowx - 1);
    } else if (nowx == len.at(i - 1) + 2) {
        return padc.at(i - 1) + 1;
    } else if (nowx <= 2 * len.at(i - 1) + 2) {
        return padc.at(i - 1) + 1 + rec(i - 1, nowx - (len.at(i - 1) + 2));
    } else if (nowx == 2 * len.at(i - 1) + 3) {
        return padc.at(i - 1) + 1 + padc.at(i - 1);
    } else {
        return 0;
    }
}
int main()
{
    __SPEED_UP__
    len.at(0) = 1;
    padc.at(0) = 1;
    rep(i, 50)
    {
        len.at(i + 1) = len.at(i) * 2 + 3;
        padc.at(i + 1) = padc.at(i) * 2 + 1;
    }
    cin >> n >> x;
    cout << rec(n, x) << endl;
}
