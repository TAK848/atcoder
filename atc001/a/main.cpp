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
bool is_valid_move(int h, int w, vector<string>& way, vector<vector<bool>>& checked, int x, int y)
{
    if (x < 0 || x >= h || y < 0 || y >= w)
        return false;
    if (way.at(x).at(y) == '#')
        return false;
    if (checked.at(x).at(y))
        return false;
    return true;
}
bool reacheable(int h, int w, vector<string>& way, vector<vector<bool>>& checked, int x, int y, int goal_x, int goal_y)
{
    if (x == goal_x && y == goal_y)
        return true;
    checked.at(x).at(y) = true;
    rep(i, 4)
    {
        int nx = x + dx4.at(i);
        int ny = y + dy4.at(i);
        if (is_valid_move(h, w, way, checked, nx, ny))
            if (reacheable(h, w, way, checked, nx, ny, goal_x, goal_y))
                return true;
    }
    return false;
}

int main()
{
    __SPEED_UP__
    int h, w;
    cin >> h >> w;
    vector<string> way(h);
    rep(i, h) cin >> way.at(i);
    vector<vector<bool>> checked(h, vector<bool>(w, false));
    int countflag = 2;
    int start_x, start_y, end_x, end_y;
    rep(i, h)
    {
        rep(j, w)
        {
            if (way.at(i).at(j) == 's') {
                start_x = i;
                start_y = j;
                countflag--;
            }
            if (way.at(i).at(j) == 'g') {
                end_x = i;
                end_y = j;
                countflag--;
            }
            if (countflag == 0)
                break;
        }
        if (countflag == 0)
            break;
    }
    cout << (YesNo(reacheable(h, w, way, checked, start_x, start_y, end_x, end_y))) << '\n';
}
