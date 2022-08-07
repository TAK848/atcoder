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
    bool flag = false;
    cin >> n;
    rep(i, n)
    {
        char kind;
        cin >> kind;
        if (kind == 'Y') {
            flag = true;
            break;
        }
    }
    cout << (flag ? "Four" : "Three") << '\n';
}
