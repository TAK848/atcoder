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
    int n;
    cin >> n;
    map<string, int> mst;
    rep(i, n)
    {
        string s;
        cin >> s;
        mst[s]++;
        // cout << mst[s] << '\n';
    }
    int m;
    cin >> m;
    rep(i, m)
    {
        string s;
        cin >> s;
        mst[s]--;
        // cout << mst[s] << '\n';
    }
    int max = 0;
    // for (const auto& [key, value] : mst) {
    //     // cout << key << " " << value << '\n';
    //     max = std::max(max, value);
    // }
    // cout << max << '\n';
    int max = max_element(all(mst), [](const auto& x, const auto& y) { return x.second < y.second; })->second;
    cout << (max > 0 ? max : 0) << '\n';
}
