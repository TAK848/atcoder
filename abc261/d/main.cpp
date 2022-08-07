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
int n, m;
vector<int> x(n);
vector<int> c(m);
vector<int> y(m);

int dp(int i, int j)
{
    if (i == n) {
        return 0;
    }
    if (j == m) {
        return 0;
    }
    if (x[i] == y[j]) {
        return dp(i + 1, j + 1) + c[j];
    }
    return max(dp(i + 1, j), dp(i, j + 1));
}

int main()
{
    __SPEED_UP__
    cin >> n >> m;
    rep(i, n)
    {
        cin >> x.at(i);
    }
    rep(i, m)
    {
        cin >> c.at(i) >> y.at(i);
    }
}
