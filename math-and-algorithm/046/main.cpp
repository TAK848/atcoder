#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)
#define repstep(i, n, step) for (mi i = (mi)(n); i < (mi)(n) + (mi)(step); i++)
#define rep2(i, m, n) for (mi i = (mi)(m); i < (mi)(n); i++)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")
const vmi dx4 = { 1, 0, -1, 0 };
const vmi dy4 = { 0, 1, 0, -1 };

// // aよりもbが大きいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmax(T& a, const T& b)
// {
//     if (a < b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }
// // aよりもbが小さいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmin(T& a, const T& b)
// {
//     if (a > b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi r, c;
    cin >> r >> c;
    mi sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy--;
    sx--;
    gy--;
    gx--;
    vvb b(r, vb(c, false));
    rep(i, r)
    {
        rep(j, c)
        {
            char input;
            cin >> input;
            b.at(i).at(j) = input == '.';
        }
    }
    queue<pair<mi, mi>> q;
    q.push({ sy, sx });
    vvmi d(r, vmi(c, -1));
    d.at(sy).at(sx) = 0;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (p.first == gy && p.second == gx) {
            break;
        }
        rep(i, 4)
        {
            mi ny = p.first + dy4.at(i);
            mi nx = p.second + dx4.at(i);
            if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
                continue;
            }
            if (d.at(ny).at(nx) == -1 && b.at(ny).at(nx)) {
                d.at(ny).at(nx) = d.at(p.first).at(p.second) + 1;
                q.push({ ny, nx });
            }
        }
    }
    cout << d.at(gy).at(gx) << endl;
}
