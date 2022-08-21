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
    mi n, p, q, r;
    cin >> n >> p >> q >> r;
    vmi a(n);
    cin >> a;
    // cin >> a.at(0);
    // rep(i, n - 1)
    // {
    //     cin >> a.at(i + 1);
    //     a.at(i + 1) += a.at(i);
    // }
    mi st = 0;
    mi value = 0;
    // vector<pair<mi, mi>> p_kukan;
    set<mi> p_end;
    rep(ed, n)
    {
        value += a.at(ed);
        while (st <= ed && value > p) {
            value -= a.at(st);
            st++;
        }
        if (value == p) {
            // p_kukan.emplace_back(st, ed);
            p_end.insert(ed);
            // cout << st << " " << ed << endl;
        }
    }
    // cout << "---" << endl;
    st = 0;
    value = 0;
    // vector<pair<mi, mi>> q_kukan;
    set<mi> q_end;
    // set<mi>
    rep(ed, n)
    {
        value += a.at(ed);
        while (st <= ed && value > q) {
            value -= a.at(st);
            st++;
        }
        if (value == q) {
            if (p_end.count(st - 1)) {
                // q_kukan.emplace_back(st, ed);
                q_end.insert(ed);
                // cout << st << " " << ed << endl;
            }
            // q_kukan.emplace_back(st, ed);
            // cout << st << " " << ed << endl;
        }
    }
    // cout << "---" << endl;
    st = 0;
    value = 0;
    // vector<pair<mi, mi>> r_kukan;
    set<mi> r_end;
    rep(ed, n)
    {
        value += a.at(ed);
        while (st <= ed && value > r) {
            value -= a.at(st);
            st++;
        }
        if (value == r) {
            if (q_end.count(st - 1)) {
                // r_kukan.emplace_back(st, ed);
                r_end.insert(ed);
                // cout << st << " " << ed << endl;
            }
            // r_kukan.emplace_back(st, ed);
            // cout << st << " " << ed << endl;
        }
    }
    cout << YesNo(!r_end.empty()) << endl;
}
