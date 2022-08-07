#include <bits/stdc++.h>
using namespace std;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repstep(i, n, step) for (int i = (int)(n); i < (int)(n) + (int)(step); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define repstep2(i, m, n, step) for (int i = (int)(m); i < (int)(n) + (int)(step); i++)
#define all(v) v.begin(), v.end()
// #define endl '\n'

int main()
{
    __SPEED_UP__
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n, '-'));
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        a.at(x - 1).at(y - 1) = 'o';
        a.at(y - 1).at(x - 1) = 'x';
    }
    rep(i, n)
    {
        rep(j, n) cout << a.at(i).at(j) << (j == n - 1 ? '\n' : ' ');
    }
}
