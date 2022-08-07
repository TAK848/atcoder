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

int count_report_num(vector<vector<int>>& children, int target)
{
    // cout << "target: " << target << endl;
    int count = children.at(target).size();
    if (count == 0)
        return 1;
    int sum = 1;
    rep(i, count)
    {
        sum += count_report_num(children, children.at(target).at(i));
    }
    // cout << "target: " << target << " sum: " << sum << endl;
    return sum;
}

int main()
{
    __SPEED_UP__
    int n;
    cin >> n;
    vector<int> p(n);
    p.at(0) = -1;
    rep2(i, 1, n) cin >> p.at(i);
    vector<vector<int>> children(n);
    rep2(i, 1, n)
    {
        children.at(p.at(i)).push_back(i);
    }
    rep(i, n)
    {
        cout << count_report_num(children, i) << '\n';
    }
}
