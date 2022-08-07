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
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    vector<int> p(n);
    rep(i, n) cin >> p.at(i);
    int count = 0;
    // for (auto i : a) {
    //     for (auto j : p) {
    //         if (i + j == s) {
    //             count++;
    //         }
    //     }
    // }
    rep(i, n)
    {
        rep(j, n)
        {
            if (a.at(i) + p.at(j) == s) {
                count++;
            }
        }
    }
    cout << count << '\n';
}
