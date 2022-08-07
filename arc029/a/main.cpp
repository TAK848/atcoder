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
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// #define endl '\n'

int main()
{
    __SPEED_UP__
    int n;
    cin >> n;
    vector<int> t(n);
    rep(i, n) cin >> t.at(i);
    int a, b;
    int ans = INT_MAX;
    rep(i, (1 << n))
    {
        bitset<4> bs(i);
        a = 0;
        b = 0;
        rep(j, n)
        {
            if (bs.test(j))
                a += t.at(j);
            else
                b += t.at(j);
        }
        ans = min(ans, max(a, b));
        // int count = 0;
        // rep(j, n) {
        //     if ((i >> j) & 1) {
        //         count += t.at(j);
        //     }
        // }
        // cout << count << '\n';
    }
    cout << ans << '\n';
}
