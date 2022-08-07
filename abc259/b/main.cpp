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
    int a, b, d;
    cin >> a >> b >> d;
    double first_rad = atan2(b, a);
    // cout << first_rad * 180 / M_PI << '\n';
    double finally_rad = first_rad + d * M_PI / 180;
    // cout << finally_rad * 180 / M_PI << '\n';
    double after_a, after_b;
    double length = sqrt(a * a + b * b);
    after_a = length * cos(finally_rad);
    after_b = length * sin(finally_rad);
    cout << fixed << setprecision(20) << after_a << ' ' << after_b << '\n';
    // cout << after_a << ' ' << after_b << '\n';
}
