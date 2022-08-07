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
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(all(a));
    int alice = 0, bob = 0;
    rep(i, n)
    {
        if (i % 2 == 0)
            alice += a.at(n - i - 1);
        else
            bob += a.at(n - i - 1);
    }
    cout << alice - bob << '\n';
}
