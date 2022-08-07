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

// int digit_sum(int n)
// {
//     int res = 0;
//     while (n) {
//         res += n % 10;
//         n /= 10;
//     }
//     return res;
// }

int main()
{
    __SPEED_UP__
    int n;
    cin >> n;
    cout << n * 2 << '\n';
    int count = n / 4;
    if (n - count * 4 != 0) {
        cout << n - count * 4;
    }
    rep(i, count) cout << '4';
    cout << '\n';
}
