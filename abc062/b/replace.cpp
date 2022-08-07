#include <bits/stdc++.h>
using namespace std;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repstep(i, n, step) for (int i = (int)(n); i < (int)(n) + (int)(step); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define repstep2(i, m, n, step) for (int i = (int)(m); i < (int)(n) + (int)(step); i++)
// #define endl '\n'

int main()
{
    __SPEED_UP__
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h + 2, vector<char>(w + 2, '#'));
    rep(i, h) rep(j, w) cin >> s.at(i + 1).at(j + 1);
    rep(i, h + 2)
    {
        rep(j, w + 2) cout << s.at(i).at(j);
        cout << '\n';
    }
}
