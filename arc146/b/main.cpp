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
    mi n, minp, k;
    cin >> n >> minp >> k;
    bitset<32> m(minp);
    vmi a(n);
    cin >> a;
    sort(all(a), greater<mi>());
    // vector<bitset<32>> a(n, bitset<32>(0));
    // rep(i, n)
    // {
    //     a.at(i) = bitset<32>(ai.at(i));
    // }
    // rep(i, n) cout << a.at(i) << endl;
    mi ans = 0;
    mi startbit = 0;
    // cout << m << " m" << endl;
    vmi kouho;
    mi nokori_temp = minp;
    bool flag = false;
    rep(ri, 31)
    {
        mi i = 30 - ri;
        mi cnt = 0;
        mi nokori = nokori_temp;
        // cout << bitset<12>(1 << i) << " " << cnt << " " << nokori << endl;
        mi border = 1 << i;
        rep(j, (flag ? k : n))
        {
            // if (nokori - (border - a.at(j)) >= 0) {
            // if (!flag) {
            nokori -= max((mi)0, border - a.at(j));
            // } else {
            //     nokori -= border - a.at(j);
            // }
            // }
            // cout << "aaa " << a.at(j) << " " << max((mi)0, border - a.at(j)) << " " << nokori << endl;
            if (nokori >= 0) {
                // kouho.push_back(a.at(j));
                cnt++;
                if (cnt == k) {
                    break;
                }
            } else {
                // if (!flag) {
                nokori += max((mi)0, border - a.at(j));
                // } else {
                //     nokori += (border - a.at(j));
                // }
                break;
            }
            // if (a.at(j).test(i)) {
            //     cnt++;
            // }
        }
        // cout << i << ": " << cnt << " " << endl;
        if (cnt >= k) {
            flag = true;
            startbit = max(startbit, i);
            // cout << i << "bityes" << cnt << endl;
            ans |= 1 << i;
            bitset<32> inorderor(0);
            nokori_temp = nokori;
            // cnt = 0;
            // break;
        }
        // cout << "bef ";
        // rep(i, n) cout << a.at(i) << ' ';
        // cout << endl;
        rep(i, n)
        {
            if (cnt >= k)
                a.at(i) = max(border, a.at(i));
            a.at(i) = (border - 1) & a.at(i);
            // cout << a.at(i) << endl;
        }
        sort(a.begin(), a.begin() + k, greater<mi>());
        // cout << "af  ";
        // rep(i, n) cout << a.at(i) << ' ';
        // cout << "ans: " << ans << endl;
    }
    // ans += (1 << startbit);
    // cout << "startbit: " << startbit << " " << pow(2, startbit) << endl;
    // cout << "ans: " << ans << endl;
    cout << ans << '\n';
}
