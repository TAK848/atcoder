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
using modi = modint998244353;
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
    mi n, m;
    cin >> n >> m;
    vmi p(n);
    cin >> p;
    vmi revp(n);
    rep(i, n)
    {
        p.at(i)--;
        revp.at(p.at(i)) = i;
    }
    vector<modi> wa(m + 1);
    wa.at(0) = 0;
    rep2(i, 1, m + 1)
    {
        wa.at(i) = wa.at(i - 1) + i;
        // cout << wa.at(i).val() << endl;
    }
    modi ans = 0;
    modi onajicounter = 0;
    mi counter = 0;
    mi nokori = n;
    vb a(n, false), api(n, false);
    mi acount = 0, apicount = 0;
    rep(i, n)
    {
        if (i == p.at(i)) {
            // ans *= m;
            onajicounter++;
            counter++;
            a.at(i) = true;
            api.at(i) = true;
            continue;
        }
        if (a.at(i) && api.at(i))
            continue;

        if (nokori - counter - 3 > 0)
            ans += wa.at(m - 1) * modi(m).pow(nokori - counter - 3) * (onajicounter.val() == 0 ? 1 : modi(m).pow(onajicounter.val()));
        else if (nokori - counter - 3 == 0)
            ans += wa.at(m - 1) * (onajicounter.val() == 0 ? 1 : modi(m).pow(onajicounter.val()));
        if (a.at(i)) {
            api.at(i) = true;
            a.at(p.at(i)) = true;
            // if (a.at(p.at(i) && api.at(p.at(i))))
            //     nokori--;
            // } else if (api.at(i)) {

        } else if (api.at(i)) {
            a.at(i) = true;
            api.at(revp.at(i)) = true;
            // if (a.at(revp.at(i)) && api.at(revp.at(i)))
            //     nokori--;

        } else {
            a.at(i) = true;
            a.at(p.at(i)) = true;
            api.at(i) = true;
            api.at(revp.at(i)) = true;
            // if (a.at(p.at(i) && api.at(p.at(i))))
            //     // nokori--;
            // if (a.at(revp.at(i)) && api.at(revp.at(i)))
            //     // nokori--;
        }
        nokori--;

        onajicounter = 0;
    }
    if (onajicounter.val() != 0) {
        // ans *= modi(m).pow(onajicounter.val());
    }
    cout << ans.val() << endl;
    cout << onajicounter.val() << endl;
    modi aaa = modi(m).pow(n);
    modi bbb = modi(m).pow(n - counter);
    modi ans2 = (aaa - bbb) / 2;
    cout << ans2.val() << endl;
}
