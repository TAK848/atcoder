#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
// using modi = modint1000000007;
// using modi = modint998244353;
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
    mi l, r;
    cin >> l >> r;
    vb prime(r - l + 1, true);
    if (l == 1)
        prime.at(0) = false;
    // get the number of Primes between l and r
    mi checkmax = sqrt(r);
    vb baseprime(checkmax + 1, true);
    baseprime.at(0) = baseprime.at(1) = false;
    rep2(i, 2, sqrt(checkmax) + 1)
    {
        if (baseprime.at(i)) {
            for (mi j = 2 * i; j < checkmax + 1; j += i) {
                if (j % i == 0)
                    baseprime.at(j) = false;
            }
        }
    }
    rep2(i, 2, checkmax + 1)
    {
        if (!baseprime.at(i))
            continue;
        mi minv = ((l - 1) / i + 1) * i;
        for (mi j = minv; j <= r; j += i) {
            if (i != j && j % i == 0) {
                prime.at(j - l) = false;
            }
        }
    }
    mi ans = 0;
    rep(i, r - l + 1)
    {
        if (prime.at(i)) {
            ans++;
        }
    }
    cout << ans << '\n';
}
