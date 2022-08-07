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
    mi top_b_bottom_a_count = 0;
    mi top_b_count = 0;
    mi bottom_a_count = 0;
    mi ans = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        bool now_a = false;
        mi flagcount = 0;
        if (s.at(0) == 'B') {
            top_b_count++;
            flagcount++;
        } else if (s.at(0) == 'A') {
            now_a = true;
        }
        mi size = s.size();
        rep(j, size)
        {
            if (j == 0)
                continue;

            if (now_a && s.at(j) == 'B') {
                ans++;
            } else if (j == size - 1 && s.at(j) == 'A') {
                bottom_a_count++;
                flagcount++;
            }
            now_a = (s.at(j) == 'A');
        }
        if (flagcount == 2) {
            top_b_bottom_a_count++;
            top_b_count--;
            bottom_a_count--;
        }
    }
    // cout << ans << " " << top_b_bottom_a_count << " " << top_b_count << " " << bottom_a_count << endl;
    if (top_b_count == 0 && bottom_a_count == 0) {
        // cout << ans << endl;
        ans += max(top_b_bottom_a_count - (mi)1, (mi)0);
    } else {
        // cout << ans + top_b_bottom_a_count << endl;
        ans += min(top_b_bottom_a_count + min(top_b_count, bottom_a_count), n - 1);
    }
    cout << ans << endl;
}
