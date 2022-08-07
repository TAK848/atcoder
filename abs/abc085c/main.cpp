#include <iostream>
using namespace std;
using mi = int_fast32_t;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)

int main()
{
    __SPEED_UP__
    mi n, y;
    cin >> n >> y;
    rep(i, n + 1)
    {
        rep(j, n - i + 1)
        {
            if (i + j + ((y - (10000 * i) - (5000 * j)) / 1000) == n) {
                cout << i << " " << j << " " << (y - (10000 * i) - (5000 * j)) / 1000 << '\n';
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << '\n';
}
