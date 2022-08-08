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
mi n, m, q;
vmi a, b, c, d;
mi rec(vmi A)
{
    mi size = A.size();
    if (size == n) {
        // rep(i, size)
        // {
        //     cout << A.at(i) << " ";
        // }
        // cout << endl;
        mi score = 0;
        rep(i, q)
        {
            if (A.at(b.at(i)) - A.at(a.at(i)) == c.at(i)) {
                score += d.at(i);
            }
        }
        // cout << " " << score << endl;
        return score;
    }
    mi score = 0;
    mi start = size == 0 ? 0 : A.at(size - 1);
    rep2(i, start, m)
    {
        A.push_back(i);
        score = max(score, rec(A));
        // break;
        A.pop_back();
    }
    return score;
}
int main()
{
    __SPEED_UP__
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    vmi A;
    rep(i, q)
    {
        mi ai, bi, ci, di;
        cin >> ai >> bi >> ci >> di;
        a.at(i) = ai - 1;
        b.at(i) = bi - 1;
        c.at(i) = ci;
        d.at(i) = di;
    }
    cout << rec(A) << endl;
}
