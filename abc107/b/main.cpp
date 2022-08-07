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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> a(h, vector<char>(w));
    vector<bool> h_d(h, false);
    vector<bool> w_d(w, false);
    rep(i, h) rep(j, w)
    {
        cin >> a.at(i).at(j);
        if (a.at(i).at(j) == '#') {
            h_d.at(i) = true;
            w_d.at(j) = true;
        }
    }
    rep(i, h)
    {
        if (h_d.at(i)) {
            rep(j, w)
            {
                if (w_d.at(j)) {
                    cout << a.at(i).at(j);
                }
            }
            cout << '\n';
        }
    }
}
