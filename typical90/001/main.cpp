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
    mi n, l, k;
    cin >> n >> l >> k;
    vmi a(n);
    rep(i, n) cin >> a[i];
    // 答えで2分探索
    mi ok = 0, ng = l;
    while (ng - ok > 1) {
        mi mid = (ok + ng) / 2;
        bool flag = false;
        mi place = 0;
        mi count = 1;
        rep(i, n)
        {
            if (a.at(i) - place >= mid) {
                place = a.at(i);
                count++;
                if (count == k + 1) {
                    if (l - place >= mid) {
                        flag = true;
                    }
                    break;
                }
                // ok = true;
            }
            // else {
            //     place += a.at(i);
            // }
            // if (a[i] % mid != 0) {
            //     ok = false;
            //     break;
            // }
        }
        if (flag) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
