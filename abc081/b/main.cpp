#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
// #define endl '\n'

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int min = INT_MAX;
    rep(i, n)
    {
        int a;
        cin >> a;
        rep(j, min)
        {
            if (a & 0b1) {
                min = j;
                break;
            }
            a = a >> 1;
        }
        // min = min(min, a);
    }
    cout << min << '\n';
}
