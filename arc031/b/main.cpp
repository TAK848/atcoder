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
bool is_valid_move(vector<string>& island, vector<vector<bool>>& checked, int x, int y)
{
    if (x < 0 || x >= 10 || y < 0 || y >= 10)
        return false;
    if (island.at(x).at(y) == 'x')
        return false;
    if (checked.at(x).at(y))
        return false;
    return true;
}
void reachable_set(vector<string>& island, vector<vector<bool>>& checked, int x, int y)
{
    // if (x == n - 1 && y == n - 1)
    //     return true;
    // cout << x << " " << y << endl;
    checked.at(x).at(y) = true;
    rep(i, 4)
    {
        int nx = x + dx4.at(i);
        int ny = y + dy4.at(i);
        if (is_valid_move(island, checked, nx, ny)) {
            // checked.at(nx).at(ny) = true;
            reachable_set(island, checked, nx, ny);
        }
    }
    // return false;
}
bool check_one_island(vector<string> island, vector<vector<bool>> island_zone, int x, int y)
{
    island.at(x).at(y) = 'o';
    rep(i, 10) rep(j, 10)
    {
        if (island.at(i).at(j) == 'o') {
            reachable_set(island, island_zone, i, j);
            rep(k, 10) rep(l, 10)
            {
                if (island.at(k).at(l) == 'o' && !island_zone.at(k).at(l))
                    return false;
            }
            return true;
        }
    }
    return false;
}

int main()
{
    __SPEED_UP__
    vector<string> island(10);
    rep(i, 10)
    {
        cin >> island.at(i);
    }
    vector<vector<bool>> island_zone(10, vector<bool>(10, false));
    rep(i, 10)
    {
        rep(j, 10)
        {
            // cout << "ya" << endl;
            if (island.at(i).at(j) == 'x') {
                // cout << "NO" << endl;
                // vector<string> new_island(10);
                // new_island.at(i).at(j) = 'o';
                // cout << "ya" << endl;
                bool flag = check_one_island(island, island_zone, i, j);
                if (flag) {
                    cout << "YES" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "NO" << '\n';
}
