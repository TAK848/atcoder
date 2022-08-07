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
// long long combi(long long n, long long k)
// {
//     if (n == k || k == 0)
//         return 1;
//     else {
//         return combi(n - 1, k - 1) + combi(n - 1, k);
//     }
// }
mi n, m;
void next(mi i, mi step, vmi c)
{
    // cout << i << " " << step << " " << c.at(0) << " ";
    // rep(j, n)
    // {
    //     cout << c.at(j);
    //     if (j != n - 1) {
    //         cout << " ";
    //     } else {
    //         cout << endl;
    //     }
    // }
    if (step == n) {
        rep(j, n)
        {
            cout << c.at(j);
            if (j != n - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
        return;
    } else {
        rep2(j, c.at(step - 1), m)
        {
            // if (c.at(i) + j <= n) {
            //     c.at(i) += j;
            c.at(step) = j + 1;
            next(i + 1, step + 1, c);
            //     c.at(i) -= j;
            // }
        }
    }
    return;
}
int main()
{
    __SPEED_UP__
    cin >> n >> m;
    // cout << n << m << endl;
    // mi count = combi(n, m);
    vmi base;
    rep(i, n)
    {
        base.push_back(0);
    }
    rep(i, m - n)
    {
        base.push_back(1);
    }
    do {
        mi counter = 0;
        rep(i, m)
        {
            if (base.at(i) == 0) {
                counter++;
                cout << i + 1;
                if (counter != n) {
                    cout << " ";
                }
            }
        }
        cout << endl;
    } while (next_permutation(all(base)));

    // rep(i, m)
    // {
    //     vmi v(n);
    //     v.at(0) = i + 1;
    //     // cout << i + 1 << " ";
    //     next(i + 1, 1, v);
    // }
}
