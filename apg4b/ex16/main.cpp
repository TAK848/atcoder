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
    vector<int> data(5);
    rep(i, 5) cin >> data.at(i);

    bool flag = false;
    rep(i, 4)
    {
        if (data.at(i) == data.at(i + 1)) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << '\n';
}
