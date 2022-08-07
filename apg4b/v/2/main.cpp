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
const vector<int> dx4 = { 0, 0, 1, -1 };
const vector<int> dy4 = { 1, -1, 0, 0 };

// #define endl '\n'
bool is_valid_move(int n, vector<string>& way, vector<vector<bool>>& checked, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    if (way.at(x).at(y) == '#')
        return false;
    if (checked.at(x).at(y))
        return false;
    return true;
}
bool reacheable(int n, vector<string>& way, vector<vector<bool>>& checked, int x, int y)
{
    if (x == n - 1 && y == n - 1)
        return true;
    checked.at(x).at(y) = true;
    rep(i, 4)
    {
        int nx = x + dx4.at(i);
        int ny = y + dy4.at(i);
        if (is_valid_move(n, way, checked, nx, ny))
            if (reacheable(n, way, checked, nx, ny))
                return true;
    }
    return false;
}

int main()
{
    __SPEED_UP__
    int n;
    cin >> n;
    vector<string> way(n);
    rep(i, n) cin >> way.at(i);
    vector<vector<bool>> checked(n, vector<bool>(n, false));
    cout << (YesNo(reacheable(n, way, checked, 0, 0))) << '\n';
}
