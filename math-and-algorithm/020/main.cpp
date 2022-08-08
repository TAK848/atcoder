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

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vector<vector<vector<mi>>> dp(n, vector<vector<mi>>(1000, vector<mi>(5, 0)));
    vmi ans(n);

    rep(i, n)
    {
        mi num;
        cin >> num;
        if (num != 1000) {
            dp.at(i).at(num).at(1) += 1;
        }
        if (i == 0) {
            continue;
        }
        rep2(j, 1, 1000)
        {
            rep2(k, 1, 5)
            {
                if (dp.at(i - 1).at(j).at(k) != 0) {
                    dp.at(i).at(j).at(k) += dp.at(i - 1).at(j).at(k);
                    if (j + num < 1000 && k + 1 < 5) {
                        dp.at(i).at(j + num).at(k + 1) += dp.at(i - 1).at(j).at(k);
                    } else if (j + num == 1000 && k + 1 == 5) {
                        ans.at(i) += dp.at(i - 1).at(j).at(k);
                    }
                }
            }
        }
        ans.at(i) += ans.at(i - 1);
    }
    cout << ans.at(n - 1) << endl;
}
