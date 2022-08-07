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
#define INT_DIV_CEIL(a, b) (a % b == 0 ? a / b : a / b + 1)

// #define endl '\n'
int min_solve_num(vector<int>& p, vector<int>& c, int d, int g, int problem_num, int sum_count, int sum_point)
{
    // cout << "d: " << d << " g: " << g << " problem_num: " << problem_num << " sum_count: " << sum_count << " sum_point: " << sum_point << endl;
    if (problem_num == d - 1) {
        if (sum_point >= g) {
            // cout << sum_count << endl;
            return sum_count;
        } else if (sum_point + (p.at(problem_num) * (problem_num + 1) * 100) + c.at(problem_num) < g) {
            // cout << INT_MAX << endl;
            return INT_MAX;
        } else {
            int aaa = INT_DIV_CEIL((g - sum_point), ((problem_num + 1) * 100));
            // cout << sum_count + min(p.at(problem_num), aaa) << endl;
            return sum_count + min(p.at(problem_num), aaa);
        }
    }
    int min_num = INT_MAX;
    rep(i, p.at(problem_num) + 1)
    {
        // cout << "problem_num:" << problem_num << " i: " << i << endl;
        int point = sum_point + i * (problem_num + 1) * 100;
        if (i == p.at(problem_num)) {
            // cout << "give bonus!" << endl;
            point += c.at(problem_num);
        }
        if (point >= g && i != p.at(problem_num)) {
            // cout << "point: " << point << " i: " << i << " sum_count + i: " << sum_count + i << endl;
            // return sum_count + i;
            continue;
        }
        min_num = min(min_num, min_solve_num(p, c, d, g, problem_num + 1, sum_count + i, point));
        // cout << "problem_num:" << problem_num << " i: " << i << endl;
    }
    return min_num;
}

int main()
{
    __SPEED_UP__
    int d, g;
    cin >> d >> g;
    vector<int> p(d), c(d);
    rep(i, d)
    {
        cin >> p.at(i) >> c.at(i);
    }
    // rep(i, p.at())
    cout << min_solve_num(p, c, d, g, 0, 0, 0) << '\n';
}
