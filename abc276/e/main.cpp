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
    mi h, w;
    cin >> h >> w;
    vs s(h);
    cin >> s;
    // mi startx1, starty1, startx2, starty2, startx3, starty3, startx4, starty4;
    vmi startx, starty;

    rep(i, h) rep(j, w)
    {
        if (s.at(i).at(j) == 'S') {
            // startx = j;
            // starty = i;
            s.at(i).at(j) = '#';
            rep(k, 4)
            {
                mi nx = j + dx4.at(k);
                mi ny = i + dy4.at(k);
                if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                    continue;
                // if (s.at(ny).at(nx) == 'G') {
                //     cout << "Yes" << endl;
                //     return 0;
                // }
                if (s.at(ny).at(nx) == '.') {
                    // s.at(ny).at(nx) = '#';
                    startx.push_back(nx);
                    starty.push_back(ny);
                }
            }
        }
        // if (s.at(i).at(j) == 'G')
        // {
        //     goalx = j;
        //     goaly = i;
        // }
    }
    if (startx.size() < 2) {
        cout << "No" << endl;
        return 0;
    }
    // bfs
    rep(n1, startx.size()) rep(n2, startx.size())
    {
        mi sx = startx.at(n1);
        mi sy = starty.at(n1);
        if (n1 == n2)
            continue;
        mi gx = startx.at(n2);
        mi gy = starty.at(n2);
        vvb visited(h, vb(w, false));
        queue<pair<mi, mi>> que;
        que.push({ sx, sy });
        visited.at(sy).at(sx) = true;
        while (!que.empty()) {
            auto [x, y] = que.front();
            que.pop();
            if (x == gx && y == gy) {
                cout << "Yes" << endl;
                return 0;
            }
            rep(k, 4)
            {
                mi nx = x + dx4.at(k);
                mi ny = y + dy4.at(k);
                if (nx < 0 || nx >= w || ny < 0 || ny >= h)
                    continue;
                if (s.at(ny).at(nx) == '#')
                    continue;
                if (visited.at(ny).at(nx))
                    continue;
                visited.at(ny).at(nx) = true;
                que.push({ nx, ny });
            }
        }
    }
    cout << "No" << endl;
}
