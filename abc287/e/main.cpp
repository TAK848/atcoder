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
template <typename T>
inline ostream& operator<<(ostream& os, vector<T>& vec)
{
    mi size = vec.size();
    rep(i, size) os << vec.at(i) << (i + 1 == size ? "" : " ");
    return os;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vs sall(n);
    cin >> sall;
    map<tuple<char, mi, char, mi>, multiset<char>> mp;
    forall(s, sall)
    {
        mi len = s.size();
        rep(i, len)
        {
            if (i == 0) {
                if (len == 1)
                    mp[make_tuple('-', -1, s[i], i)].insert('-');
                else
                    mp[make_tuple('-', -1, s[i], i)].insert(s[i + 1]);
            } else {
                if (i == len - 1)
                    mp[make_tuple(s[i - 1], i - 1, s[i], i)].insert('-');
                else
                    mp[make_tuple(s[i - 1], i - 1, s[i], i)].insert(s[i + 1]);
            }
        }
    }
    forall(s, sall)
    {
        mi ans = 0;
        mi len = s.size();
        rep(i, len)
        {
            if (i == 0) {
                if (len == 1) {
                    ans = (mp[make_tuple('-', -1, s[i], i)].size() > 1 ? 1 : 0);

                } else {
                    bool check = (mp[make_tuple('-', -1, s[i], i)].size() > 1);
                    ans = (check ? 1 : 0);
                    if (!check) {
                        break;
                    }
                    // cout << YesNo(check) << endl;
                }

            } else {
                if (i == len - 1) {
                    bool check = mp[make_tuple(s[i - 1], i - 1, s[i], i)].size() > 1;
                    ans += (check ? 1 : 0);
                    if (!check) {
                        break;
                    }
                    // cout << YesNo(check) << endl;
                } else {
                    bool check = mp[make_tuple(s[i - 1], i - 1, s[i], i)].size() > 1;
                    ans += (check ? 1 : 0);
                    if (!check) {
                        break;
                    }
                    // cout << YesNo(check) << endl;
                }
            }
        }
        cout << ans << '\n';
    }
}
