#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
// #define endl '\n'

int main()
{
    cin.tie(0); // cin, coutの同期を切る
    ios_base::sync_with_stdio(false); // stdioとの同期を切る
    int n;
    cin >> n;
    int l, r;
    int count = 0;
    rep(i, n)
    {
        cin >> l >> r;
        count += r - l + 1;
    }
    cout << count << '\n';
}
