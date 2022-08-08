#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
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
vmi dx4 = { 1, 0, -1, 0 };
vmi dy4 = { 0, 1, 0, -1 };
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
    mi h, w;
    cin >> h >> w;
    vector<vector<bool>> p(h, vector<bool>(w, false));
    mi black_count = 0;
    rep(i, h)
    {
        string input;
        cin >> input;
        rep(j, w)
        {
            if (input.at(j) == '.') {
                p.at(i).at(j) = true;
            } else if (input.at(j) == '#') {
                black_count++;
            }
        }
    }
    queue<pair<mi, mi>> q;
    vvmi b(h, vmi(w, -1));
    b.at(0).at(0) = 1;
    q.push({ 0, 0 });
    while (!q.empty()) {
        mi y = q.front().first;
        mi x = q.front().second;
        q.pop();
        rep(i, 4)
        {
            mi ny = y + dy4.at(i);
            mi nx = x + dx4.at(i);
            if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                continue;
            }
            if (!p.at(ny).at(nx)) {
                continue;
            }
            if (b.at(ny).at(nx) != -1) {
                continue;
            }
            b.at(ny).at(nx) = b.at(y).at(x) + 1;
            q.push({ ny, nx });
        }
    }
    if (b.at(h - 1).at(w - 1) == -1) {
        cout << -1 << endl;
    } else {
        cout << h * w - black_count - b.at(h - 1).at(w - 1) << endl;
    }
}
