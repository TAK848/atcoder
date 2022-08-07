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
    rep(i, w + 2) cout << "#";
    cout << '\n';
    rep(i, h)
    {
        cin >> s[i];
        cout << "#" << s[i] << "#\n";
    }
    rep(i, w + 2) cout << "#";
    cout << '\n';
}
