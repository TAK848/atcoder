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
    const vector<int> dx8 = { -1, -1, -1, 0, 0, 1, 1, 1 };
    const vector<int> dy8 = { -1, 0, 1, -1, 1, -1, 0, 1 };
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> ans(h, vector<int>(w, 0));
    rep(i, h)
    {
        cin >> s.at(i);
    }
    rep(i, h)
    {
        rep(j, w)
        {
            if (s.at(i).at(j) == '#') {
                ans.at(i).at(j) = 9;
                rep(k, 8)
                {
                    int nx = i + dx8.at(k);
                    int ny = j + dy8.at(k);
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                        continue;
                    }
                    ans.at(nx).at(ny)++;
                }
            }
        }
    }
    rep(i, h)
    {
        rep(j, w)
        {
            cout << ((ans.at(i).at(j) >= 9) ? "#" : to_string(ans.at(i).at(j)));
        }
        cout << endl;
    }
}
