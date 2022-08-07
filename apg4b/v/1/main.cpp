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

// #define endl '\n'

int complete_time(vector<vector<int>>& children, int place)
{
    // vector<int> ans_vec;
    int max_time = 0;
    if (children.at(place).size() == 0) {
        return 0;
    }
    for (auto& child : children.at(place)) {
        max_time = max(complete_time(children, child) + 1, max_time);
    }
    return max_time;
}

int main()
{
    __SPEED_UP__
    int n;
    cin >> n;
    vector<int> p(n);
    rep2(i, 1, n) cin >> p.at(i);
    vector<vector<int>> children(n);
    rep2(i, 1, n)
    {
        int parent = p.at(i);
        children.at(parent).push_back(i);
    }
    cout << complete_time(children, 0) << '\n';
}
