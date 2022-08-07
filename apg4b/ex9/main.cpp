#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main()
{
    cin.tie(0); // cin, coutの同期を切る
    ios_base::sync_with_stdio(false); // stdioとの同期を切る
    int x, a, b;
    cin >> x >> a >> b;

    // 1.の出力
    x++;
    cout << x << endl;

    // 2.の出力
    x *= (a + b);
    cout << x << endl;

    // 3.の出力
    x *= x;
    cout << x << '\n';

    // 4.の出力
    x--;
    cout << x << endl;
}
