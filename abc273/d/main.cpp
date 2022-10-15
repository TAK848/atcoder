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

const vmi dx4 = { 1, 0, -1, 0 };
const vmi dy4 = { 0, 1, 0, -1 };
// const string dir4 = "RDLU";

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
    mi h, w, rs, cs, n;
    cin >> h >> w >> rs >> cs >> n;
    vmi r(n), c(n);
    // priority_queue<mi> wpq, hpq;
    vmi wpq, hpq;
    rep(i, n)
    {
        cin >> r.at(i) >> c.at(i);
        r.at(i)--;
        c.at(i)--;
        wpq.push_back(r.at(i) + c.at(i) * w);
        hpq.push_back(c.at(i) + r.at(i) * h);
    }
    sort(all(wpq));
    sort(all(hpq));
    // rep(i, n)
    // {
    // cout << wpq.at(i) << " " << hpq.at(i) << endl;
    // }

    mi q;
    cin >> q;
    // vmi d(q), l(q);
    vector<char> d(q);
    vmi l(q);
    rep(i, q) cin >> d.at(i) >> l.at(i);

    // map<map<mi, mi>, mi> mp;
    // rep(i, n)
    // {
    //     mi x = r.at(i), y = c.at(i);
    //     // insert map

    // //     grid.at(r.at(i) - 1).at(c.at(i) - 1) = true;
    // }

    mi x = rs - 1, y = cs - 1;
    mi wplace = x + y * w, hplace = y + x * h;

    rep(i, q)
    {
        if (d.at(i) == 'R') {
            auto iter = upper_bound(all(wpq), wplace);
            mi wplace2 = *iter;
            if (wplace + l.at(i) < wplace2) {
                wplace = wplace + l.at(i);
                hplace = hplace
                // continue;
            } else {
                wplace = wplace2;
                hplace += l.at(i) * h;
            }
            mi x2 = wplace2 % w, y2 = wplace2 / w;
            mi ans = abs(x2 - x) + abs(y2 - y);
            cout << ans << endl;
            x = x2;
            y = y2;
            wplace = wplace2;
            // }
            // else if (d.at(i) == 'L') {
        } else if (d.at(i) == 'L') {
        } else if (d.at(i) == 'U') {
        } else if (d.at(i) == 'D') {
        }
    }
}
