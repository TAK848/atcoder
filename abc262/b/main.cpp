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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        g.at(a - 1).at(b - 1) = true;
        g.at(b - 1).at(a - 1) = true;
    }
    int counter = 0;
    rep(i, n)
    {
        rep2(j, i + 1, n)
        {
            rep2(k, j + 1, n)
            {
                if (g.at(i).at(j) && g.at(j).at(k) && g.at(k).at(i)) {
                    // cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                    // return 0;
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;
}
