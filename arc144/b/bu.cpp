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
    int n, a, b;
    cin >> n >> a >> b;
    // cout << n << ' ' << a << ' ' << b << endl;
    vector<int> as(n);
    rep(i, n) cin >> as.at(i);
    sort(all(as));
    // cout << as.at(0) << ' ' << as.at(n - 1) << endl;
    int max_num = as.at(0);

    while (true) {
        as.at(0) += a;
        as.at(n - 1) -= b;
        sort(all(as));
        // cout << as.at(0) << ' ' << as.at(n - 1) << endl;
        if (as.at(0) > max_num) {
            max_num = as.at(0);
        } else {
            break;
        }
        //     if (as.at(0) < max_num) {
        //         break;
        //     }
        //     sort(all(as));
        //     max_num = max(max_num, as.at(0));
    }
    cout << max_num << '\n';
}
