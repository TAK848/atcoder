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
#define INT_DIV_CEIL(a, b) ((a) % (b) == 0 ? (a) / (b) : (a) / (b) + 1)

// #define endl '\n'
int min_solve_num(vector<int>& p, vector<int>& max_p, int d, int g, int problem_num, vector<bool> op)
{

    // cout << "d: " << d << " g: " << g << " problem_num: " << problem_num << endl;
    if (problem_num == d) {
        // rep(i, d)
        // {
        //     cout << (op.at(i) ? "1" : "0") << (i == d - 1 ? "\n" : " ");
        // }
        // cout << endl;
        int result_point = 0;
        int result_count = 0;
        rep(i, d)
        {
            if (op.at(i)) {
                result_point += max_p.at(i);
                result_count += p.at(i);
            }
        }
        if (result_point >= g) {
            return result_count;
        }
        rep(i, d)
        {
            int place = d - i - 1;
            int need_count = INT_DIV_CEIL(g - result_point, (place + 1) * 100);
            // cout << "g: " << g << " result_point: " << result_point << " g-result_point: " << g - result_point << " (place + 1) * 100: " << (place + 1) * 100 << " need_count: " << need_count << endl;
            // cout << "place: " << place << " need_count: " << need_count << endl;
            if (!op.at(place)) {
                if (need_count >= p.at(place)) {
                    return INT_MAX;
                }
                return result_count + need_count;
                break;
            }
        }
        return -1;

        // if (sum_point >= g) {
        //     // cout << sum_count << endl;
        //     return sum_count;
        // } else if (sum_point + (p.at(problem_num) * (problem_num + 1) * 100) + c.at(problem_num) < g) {
        //     // cout << INT_MAX << endl;
        //     return INT_MAX;
        // } else {
        //     int aaa = INT_DIV_CEIL((g - sum_point), ((problem_num + 1) * 100));
        //     // cout << sum_count + min(p.at(problem_num), aaa) << endl;
        //     return sum_count + min(p.at(problem_num), aaa);
        // }
    }
    int a = min_solve_num(p, max_p, d, g, problem_num + 1, op);
    op.at(problem_num) = true;
    int b = min_solve_num(p, max_p, d, g, problem_num + 1, op);
    return min(a, b);

    // int min_num = INT_MAX;
    // rep(i, p.at(problem_num) + 1)
    // {
    //     // cout << "problem_num:" << problem_num << " i: " << i << endl;
    //     int point = sum_point + i * (problem_num + 1) * 100;
    //     if (i == p.at(problem_num)) {
    //         // cout << "give bonus!" << endl;
    //         point += c.at(problem_num);
    //     }
    //     if (point >= g && i != p.at(problem_num)) {
    //         // cout << "point: " << point << " i: " << i << " sum_count + i: " << sum_count + i << endl;
    //         // return sum_count + i;
    //         continue;
    //     }
    //     min_num = min(min_num, min_solve_num(p, c, d, g, problem_num + 1, sum_count + i, point, op));
    //     // cout << "problem_num:" << problem_num << " i: " << i << endl;
    // }
    // return min_num;
}

int main()
{
    __SPEED_UP__
    int d, g;
    cin >> d >> g;
    vector<int> p(d), max_p(d);
    int tmp;
    rep(i, d)
    {
        cin >> p.at(i) >> tmp;
        max_p.at(i) = (i + 1) * 100 * p.at(i) + tmp;
    }
    // rep(i, p.at())
    // cout << "hello" << endl;
    vector<bool> op(d, false);
    cout << min_solve_num(p, max_p, d, g, 0, op) << '\n';
    // op.at(0) = true;
    // cout << min_solve_num(p, max_p, d, g, 0, op) << '\n';
}
