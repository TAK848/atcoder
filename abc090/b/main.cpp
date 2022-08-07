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
    int count = 0;
    string x;
    rep2(i, a, b + 1)
    {
        string x = to_string(i);
        string y = x;
        reverse(y.begin(), y.end());
        if (x == y)
            count++;
    }
    cout << count << '\n';
}
