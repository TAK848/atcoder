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
                if (i - 1 >= 0) {
                    ans.at(i - 1).at(j)++;
                    if (j - 1 >= 0) {
                        ans.at(i - 1).at(j - 1)++;
                    }
                    if (j + 1 < w) {
                        ans.at(i - 1).at(j + 1)++;
                    }
                }
                if (i + 1 < h) {
                    ans.at(i + 1).at(j)++;
                    if (j - 1 >= 0) {
                        ans.at(i + 1).at(j - 1)++;
                    }
                    if (j + 1 < w) {
                        ans.at(i + 1).at(j + 1)++;
                    }
                }
                if (j - 1 >= 0) {
                    ans.at(i).at(j - 1)++;
                }
                if (j + 1 < w) {
                    ans.at(i).at(j + 1)++;
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
        cout << '\n';
    }
}
