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
    int n;
    int x;
    int t1 = 0xffffffff;
    int t2 = 0x0;
    cin >> n >> x;
    vector<int> t(n);
    vector<int> a(n);
    vector<int> fff(n);
    vector<int> ooo(n);
    rep(i, n)
    {
        cin >> t.at(i) >> a.at(i);
    }
    // cout << bitset<4>(x) << '\n';
    rep(i, n)
    {
        if (t.at(i) == 1) {
            // x = x & a.at(i);
            // cout << "and ";
            t1 = t1 & a.at(i);
            t2 = t2 & a.at(i);

        } else if (t.at(i) == 2) {
            // x = x | a.at(i);
            // cout << "or  ";
            t1 = t1 | a.at(i);
            t2 = t2 | a.at(i);

        } else if (t.at(i) == 3) {
            // x = x ^ a.at(i);
            // cout << "xor ";
            t1 = t1 ^ a.at(i);
            t2 = t2 ^ a.at(i);
        }
        fff.at(i) = t1;
        ooo.at(i) = t2;

        // rep(j, i + 1)
        // {
        //     if (t.at(j) == 1) {
        //         x = x & a.at(j);
        //     } else if (t.at(j) == 2) {
        //         x = x | a.at(j);
        //     } else if (t.at(j) == 3) {
        //         x = x ^ a.at(j);
        //     }
        // }
        // cout << bitset<4>(a.at(i)) << " ";
        // cout << bitset<4>(t1) << " ";
        // cout << bitset<4>(t2) << '\n';
    }
    rep(i, n)
    {
        x = ((x & fff.at(i)) | (~x & ooo.at(i)));
        cout << x << '\n';
        // cout << ((x & fff.at(i)) | (~x & ooo.at(i))) << '\n';
        // cout << bitset<4>((x & fff.at(i))) << " " << bitset<4>((~x & ooo.at(i))) << " " << bitset<4>((x & fff.at(i)) | (~x & ooo.at(i))) << '\n';
    }
}
