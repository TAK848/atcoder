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
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b; // aをbで更新
        return true;
    }
    return false;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vector<bool> dp(100001, false);
    dp.at(0) = true;
    mi su = 0;
    rep(i, n)
    {
        mi num;
        cin >> num;
        su += num;
        // cout << "num: " << num << endl;
        vector<bool> dpnow = dp;
        rep(j, 100001)
        {
            if (dpnow.at(j)) {
                // cout << j << " ";
                if (j + num <= 100001)
                    dp.at(j + num) = true;
            }
        }
        // cout << endl;
        // if (num <= s)
        //     dp.at(num) = true;
    }
    mi ans = INT32_MAX;
    rep(i, 100001)
    {
        if (dp.at(i)) {
            // cout << i << " " << su << " " << su - i << endl;
            chmin(ans, max(i, su - i));
        }
    }
    cout << ans << endl;
    // rep(i, s + 1)
    // {
    //     if (dp.at(i)) {
    //         cout << i << '\n';
    //     }
    // }
    // cout << YesNo(dp.at(s)) << endl;
}
