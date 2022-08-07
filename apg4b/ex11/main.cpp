#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
// #define endl '\n'

int main()
{
    cin.tie(0); // cin, coutの同期を切る
    ios_base::sync_with_stdio(false); // stdioとの同期を切る
    int n, a;
    cin >> n >> a;
    rep(i, n)
    {
        char op;
        int b;
        cin >> op >> b;
        if (op == '+') {
            a += b;
        } else if (op == '-') {
            a -= b;
        } else if (op == '*') {
            a *= b;
        } else if (op == '/' && b != 0) {
            a /= b;
        } else {
            cout << "error" << endl;
            break;
        }
        cout << i + 1 << ":" << a << endl;
    }
}
