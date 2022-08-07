#include <bits/stdc++.h>
using namespace std;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repstep(i, n, step) for (int i = (int)(n); i < (int)(n) + (int)(step); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define repstep2(i, m, n, step) for (int i = (int)(m); i < (int)(n) + (int)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// aよりもbが大きいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmax(T& a, const T& b)
{
    if (a < b) {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
// aよりもbが小さいならばaをbで更新する
// (更新されたならばtrueを返す)
template <typename T>
bool chmin(T& a, const T& b)
{
    if (a > b) {
        a = b; // aをbで更新
        return true;
    }
    return false;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    if (r1 <= r2 && l2 <= l1) {
        cout << r1 - l1 << '\n';
        return 0;
    } else if (r2 <= r1 && l1 <= l2) {
        cout << r2 - l2 << '\n';
        return 0;
    }
    if (l1 < r2) {
        if (r1 < l2) {
            cout << "0" << endl;
            return 0;
        } else {
            cout << min(r1 - l2, r2 - l1) << '\n';
        }
    } else {
        cout << "0" << '\n';
    }
}
