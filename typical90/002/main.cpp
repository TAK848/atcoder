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
    mi n;
    cin >> n;
    if (n % 2 == 1) {
        cout << '\n';
        return 0;
    }
    for (mi tmp = 0; tmp < (1 << n); tmp++) {
        bitset<20> bs(tmp);

        mi count = 0;
        bool flag = true;
        rep(i, n)
        {
            mi place = n - i - 1;
            // if (bs.test(i)) {
            if (tmp & (1 << place)) { // 1なら
                count--;
            } else { // 0なら
                count++;
            }
            if (count < 0) {
                flag = false;
                break;
            }
        }
        // rep(i, n)
        // {
        //     // if (bs.test(i)) {

        //     if (tmp & (1 << i)) {
        //         cout << '1';
        //     } else {
        //         cout << '0';
        //     }
        // }
        // cout << '\n';
        if (flag && count == 0) {
            rep(i, n)
            {
                mi place = n - i - 1;
                // if (bs.test(i)) {

                if (tmp & (1 << place)) {
                    cout << ')';
                } else {
                    cout << '(';
                }
            }
            cout << '\n';
        }
    }
}
