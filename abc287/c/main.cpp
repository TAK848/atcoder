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
    mi n, m;
    cin >> n >> m;
    if (n - m != 1) {
        cout << "No" << endl;
        return 0;
    }
    vvmi g(n);
    rep(i, m)
    {
        mi a, b;
        cin >> a >> b;
        a--;
        b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
    }

    mi onecount = 0;
    mi twocount = 0;
    rep(i, n)
    {
        if (g.at(i).size() == 1) {
            onecount++;
        } else if (g.at(i).size() == 2) {
            twocount++;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (onecount == 2 && twocount == n - 2) {
        // cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
        return 0;
    }
    // bool g_is_path_graph;
    // mi start;
    // mi end;
    // rep(i, n)
    // {
    //     if (g.at(i).size() == 1) {
    //         start = i;
    //         end = g.at(i).at(0);
    //         g_is_path_graph = true;
    //         break;
    //     } else if (g.at(i).size() == 2) {
    //         g_is_path_graph = false;
    //     } else {
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    // cout << YesNo(g_is_path_graph) << endl;

    vb visited(n, false);
    mi before = 0;
    mi place = 0;
    rep(i, m)
    {
        if (g.at(i).size() == 1) {
            before = i;
            place = g.at(i).at(0);
            break;
        }
    }
    visited.at(before) = true;
    visited.at(place) = true;
    // cout << before << endl;
    rep(i, m - 1)
    {
        if (i == m - 2) {
            if (g.at(place).size() != 2) {
                cout << "No" << endl;
                return 0;
            }
        } else {
            if (g.at(place).size() != 2) {
                cout << "No" << endl;
                return 0;
            }
        }
        mi next = (g.at(place).at(0) == before ? g.at(place).at(1) : g.at(place).at(0));
        // cout << next << endl;
        if (visited.at(next)) {
            cout << "No" << endl;
            return 0;
        }
        visited.at(next) = true;
        before = place;
        place = next;
    }
    mi sss = g.at(place).size();
    cout << YesNo((sss == 1)) << endl;
}
