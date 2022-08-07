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
    int x = n;

    int count = 0;
    while (true) {
        count += n % 10;
        n /= 10;
        if (n == 0)
            break;
    }
    cout << (x % count == 0 ? "Yes" : "No") << '\n';
}
