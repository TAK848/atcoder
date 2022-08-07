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
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> a(n), b(n), su(n);
    vector<bool> flag(n, false);
    rep(i, n)
    {
        cin >> a.at(i);
    }
    rep(i, n)
    {
        cin >> b.at(i);
    }
    rep(i, n)
    {
        su.at(i) = a.at(i) + b.at(i);
    }
    rep(i, x)
    {
        int max_idx = -1;
        int max_val = -1;
        rep(j, n)
        {
            if (flag.at(j)) {
                continue;
            }
            if (max_val < a.at(j)) {
                max_val = a.at(j);
                max_idx = j;
            }
        }
        flag.at(max_idx) = true;
        // cout << max_idx + 1 << "\n";
    }
    rep(i, y)
    {
        int max_idx = -1;
        int max_val = -1;
        rep(j, n)
        {
            if (flag.at(j)) {
                continue;
            }
            if (max_val < b.at(j)) {
                max_val = b.at(j);
                max_idx = j;
            }
        }
        flag.at(max_idx) = true;
        // cout << max_idx + 1 << "\n";
    }
    rep(i, z)
    {
        int max_idx = -1;
        int max_val = -1;
        rep(j, n)
        {
            if (flag.at(j)) {
                continue;
            }
            if (max_val < su.at(j)) {
                max_val = su.at(j);
                max_idx = j;
            }
        }
        flag.at(max_idx) = true;
        // cout << max_idx + 1 << "\n";
    }
    rep(i, n)
    {
        if (flag.at(i)) {
            cout << i + 1 << "\n";
        }
    }
}
