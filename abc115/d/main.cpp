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
string rec(mi i)
{
    if (memo.at(i) != "")
        return memo.at(i);
    if (i == 0) {
        memo.at(0) = "P";
        return memo.at(0);
    }
    memo.at(i) = "B" + rec(i - 1) + "P" + memo.at(i - 1) + "B";
    return memo.at(i);
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
    string check = rec(n);
    mi P_count = 0;
    rep(i, x)
    {
        if (check.at(i) == 'P')
            P_count++;
    }
    cout << P_count << endl;
}
