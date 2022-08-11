#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using modi = static_modint<1000000007>;
using vmi = vector<modi>;
using vvmi = vector<vmi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
using matrix2 = vvmi;
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
vvmi multiplication(vvmi a, vvmi b)
{
    mi size = a.size();
    vvmi c(size, vmi(size, 0));
    rep(i, size)
    {
        rep(j, size)
        {
            rep(k, size)
            {
                c.at(i).at(j) += a.at(i).at(k) * b.at(k).at(j);
            }
        }
    }
    return c;
}
vvmi power(vvmi a, mi n)
{
    vvmi p = a, q;
    bitset<64> b(n);
    bool flag = false;
    rep(i, b.size())
    {
        if (b[i]) {
            if (flag) {
                q = multiplication(q, p);
            } else {
                q = p;
                flag = true;
            }
        }
        p = multiplication(p, p);
    }
    return q;
}

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vvmi a = {
        { 2, 1 },
        { 1, 0 },
    };
    // n -= 2;
    n--;
    // n = 3;
    vvmi b = power(a, n);
    cout << (b.at(1).at(0) + b.at(1).at(1)).val() << endl;
}
