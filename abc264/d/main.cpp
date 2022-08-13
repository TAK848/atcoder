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

// #define endl '\n'

int main()
{
    __SPEED_UP__
    string s;
    cin >> s;
    vmi atc(7);
    rep(i, 7)
    {
        switch (s.at(i)) {
        case 'a':
            atc.at(i) = 0;
            break;
        case 't':
            atc.at(i) = 1;
            break;
        case 'c':
            atc.at(i) = 2;
            break;
        case 'o':
            atc.at(i) = 3;
            break;
        case 'd':
            atc.at(i) = 4;
            break;
        case 'e':
            atc.at(i) = 5;
            break;
        case 'r':
            atc.at(i) = 6;
            break;
        }
    }
    // バブルソートのカウント
    mi swaps = 0;
    rep(i, 6)
    {
        rep(j, 6 - i)
        {
            if (atc.at(j) > atc.at(j + 1)) {
                swap(atc.at(j + 1), atc.at(j));
                swaps++;
            }
        }
    }
    cout << swaps << endl;
}
