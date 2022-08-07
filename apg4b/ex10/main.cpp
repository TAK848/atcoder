#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
// #define endl '\n'

int main()
{
    cin.tie(0); // cin, coutの同期を切る
    ios_base::sync_with_stdio(false); // stdioとの同期を切る
    int a, b;
    cin >> a >> b;
    cout << "A:";
    rep(i, a)
    {
        cout << "]";
    }
    cout << '\n'
         << "B:";
    rep(i, b)
    {
        cout << "]";
    }
    cout << '\n';
}
