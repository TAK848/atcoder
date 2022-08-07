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
    int n, k;
    cin >> n >> k;
    if (k > n / 2) {
        cout << -1 << '\n';
        return 0;
    }

    int start = 1 + k;
    int ans;
    vector<bool> used(n + 1, false);
    // if(k > n / 4)
    rep2(i, 1, n + 1)
    {
        // cout << i << ' ' << k << ' ' << start << '\n';
        if (i - k > 0 && !used[i - k]) {
            ans = i - k;
            used[i - k] = true;
            // goto lablab;
        } else if (i + k > 0 && !used[i + k]) {
            ans = k + i;
            used[k + i] = true;
            // goto lablab;
        } else {
            int counter = i + k;
            while (true) {
                if (!used[counter]) {
                    ans = counter;
                    used[counter] = true;
                    break;
                }
            }
        }
        // lablab:
        // ans = (start + i) % n;
        // cout << (ans == 0 ? n : ans);
        cout << ans;
        if (i != n) {
            cout << ' ';
        } else {
            cout << '\n';
        }
    }
}
