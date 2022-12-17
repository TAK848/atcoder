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
    vvmi g(n);
    dsu d(n);
    rep(i, m)
    {
        mi a, b;
        cin >> a >> b;
        a--;
        b--;
        g.at(a).push_back(b);
        g.at(b).push_back(a);
        d.merge(a, b);
    }
    // bool is_bipartite_graph = true;
    // vb visited1(n, false);
    // vb color(n, false);
    // rep(i, n)
    // {
    //     if (visited1.at(i))
    //         continue;
    //     queue<mi> q;
    //     q.push(i);
    //     color.at(i) = true;
    //     while (!q.empty()) {
    //         mi v = q.front();
    //         q.pop();
    //         if (visited1.at(v))
    //             continue;
    //         visited1.at(v) = true;
    //         forall(u, g.at(v))
    //         {
    //             if (color.at(v))
    //                 color.at(u) = false;
    //             else
    //                 color.at(u) = true;
    //             q.push(u);
    //         }
    //     }
    // }
    // rep(i, n)
    // {
    //     forall(u, g.at(i))
    //     {
    //         if (color.at(i) == color.at(u)) {
    //             is_bipartite_graph = false;
    //             break;
    //         }
    //     }
    // }
    // if (!is_bipartite_graph) {
    //     // cout << n * (n - 1) / 2 - m << endl;
    //     cout << 0 << endl;
    //     return 0;
    // }

    // if (!is_all_connected) {
    //     // cout << n * (n - 1) / 2 - m << endl;
    //     cout << 0 << endl;
    //     return 0;
    // }

    // mi loop_count = 0;
    // vb visited3(n, false);
    // rep(i, n)
    // {
    //     if (visited3.at(i))
    //         continue;
    //     queue<mi> q;
    //     q.push(i);
    //     while (!q.empty()) {
    //         mi v = q.front();
    //         q.pop();
    //         if (visited3.at(v))
    //             continue;
    //         visited3.at(v) = true;
    //         forall(u, g.at(v))
    //         {
    //             if (u == i)
    //                 loop_count++;
    //             q.push(u);
    //         }
    //     }
    // }
    // cout << loop_count << endl;

    // 二部グラフに分ける
    if (d.groups().size() == 1) {
        set<mi> s1, s2;
        vb visited(n, false);
        rep(i, n)
        {
            if (visited.at(i))
                continue;
            queue<mi> q;
            q.push(i);
            s1.insert(i);
            while (!q.empty()) {
                mi v = q.front();
                q.pop();
                if (visited.at(v))
                    continue;
                visited.at(v) = true;
                forall(u, g.at(v))
                {
                    if (s1.count(v))
                        s2.insert(u);
                    else
                        s1.insert(u);
                    q.push(u);
                }
            }
        }
        forall(i, s1)
        {
            if (s2.count(i)) {
                cout << 0 << endl;
                return 0;
            }
        }
        rep(i, n)
        {
            if (s1.count(i) == 0 && s2.count(i) == 0) {
                cout << 0 << endl;
                return 0;
            }
        }
        // output s1
        forall(i, s1) cout << i + 1 << " ";
        cout << endl;
        // output s2
        forall(i, s2) cout << i + 1 << " ";
        cout << endl;
        cout << s1.size() * s2.size() - m << endl;
    } else {
        auto output = d.groups();
        // cout << output << endl;
        forall(ax, output)
        {
            cout << ax << endl;
        }
        if (output.size() != 2) {
            cout << 0 << endl;
            return 0;
        }
        set<mi> set1, set2;
        forall(i, output.at(0)) set1.insert(i);
        forall(i, output.at(1)) set2.insert(i);
    }
}
