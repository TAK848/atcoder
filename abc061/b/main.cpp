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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        a[x - 1][y - 1]++;
        a[y - 1][x - 1]++;
    }
    rep(i, n)
    {
        int count = 0;
        rep(j, n)
        {
            count += a[i][j];
        }
        cout << count << '\n';
    }
}
