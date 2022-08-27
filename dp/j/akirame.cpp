#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vd = vector<double>;
using vvd = vector<vd>;
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
#define forall(i, v) for (auto& i : v)
#define forallpair(i, j, v) for (auto& [i, j] : v)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// aよりもbが大きいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
// aよりもbが小さいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <typename T>
inline istream& operator>>(istream& is, vector<T>& vec)
{
    for (T& x : vec)
        is >> x;
    return is;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    cout << fixed << setprecision(16);
    mi count1 = 0, count2 = 0, count3 = 0;
    rep(i, n)
    {
        mi a;
        cin >> a;
        if (a == 1)
            count1++;
        else if (a == 2)
            count2++;
        else
            count3++;
    }
    mi a_sum = count1 + count2 * 2 + count3 * 3;
    cout << a_sum << endl;
    vector<vvd> dp(a_sum + 1, vvd(count3 + 1, vd(count2 + 1, 0)));
    // dp.at(0).at(count3).at(count2) = 1;
    rep(i, a_sum + 1)
    {
        mi nokoriall = a_sum - i;
        rep(j, count3 + 1) rep(k, count2 + 1)
        {
            mi nokori3 = count3 - j;
            mi nokori2 = count2 - k;
            mi l = i - j * 3 - k * 2;
            mi nokori1 = count1 - l;
            mi nokori_all_dish = nokori1 + nokori2 + nokori3;
            if (0 > nokori1 || nokori1 > count1) {
                continue;
            }
            // cout << nokoriall << " " << j << " " << k << " " << l << endl;
            if (nokoriall == a_sum) {
                dp.at(i).at(nokori3).at(nokori2) = 1;
            } else {
                dp.at(i).at(nokori3).at(nokori2) = 1 / (1 - (double)(n - nokori_all_dish - 1) / (double)n);
                // cout << nokoriall << " " << nokori3 << " " << nokori2 << " " << nokori1 << " " << dp.at(i).at(nokori3).at(nokori2) << endl;
                if (nokori3 != count3) {
                    dp.at(i).at(nokori3).at(nokori2) += dp.at(i - 1).at(nokori3 + 1).at(nokori2)*;
                }
                if (nokori2 != count2) {
                    dp.at(i).at(nokori3).at(nokori2) += dp.at(i - 1).at(nokori3).at(nokori2 + 1);
                }
                if (nokori1 != count1) {
                    double prob = (double)n / (double)(nokori_all_dish + 1);
                    dp.at(i).at(nokori3).at(nokori2) += dp.at(i - 1).at(nokori3).at(nokori2);
                }
            }
            cout << nokoriall << " " << nokori3 << " " << nokori2 << " " << nokori1 << " " << dp.at(i).at(nokori3).at(nokori2) << endl;
        }
    }
    cout << dp.at(a_sum).at(0).at(0) << endl;
}
