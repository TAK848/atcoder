#include <iostream>
using namespace std;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    __SPEED_UP__
    int n;
    int x;
    int t1 = 0xffffffff;
    int t2 = 0x0;
    cin >> n >> x;
    rep(i, n)
    {
        int ttt, aaa;
        cin >> ttt >> aaa;
        if (ttt == 1) {
            t1 = t1 & aaa;
            t2 = t2 & aaa;

        } else if (ttt == 2) {
            t1 = t1 | aaa;
            t2 = t2 | aaa;

        } else if (ttt == 3) {
            t1 = t1 ^ aaa;
            t2 = t2 ^ aaa;
        }
        x = ((x & t1) | (~x & t2));
        cout << x << '\n';
    }
}
