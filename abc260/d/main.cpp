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
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        rep(i, n)
        {
            cout << i + 1 << '\n';
        }
        return 0;
    }
    vector<int> p(n);
    rep(i, n)
    {
        cin >> p.at(i);
        p.at(i)--;
    }
    vector<pair<int, int>> table(n, { -1, -1 });
    vector<int> group(n, -1);
    vector<int> group_min;
    vector<int> group_count;
    // vector<int> timing;
    vector<int> ans(n, -1);
    int current_group = 0;
    rep(i, n)
    {
        int num = p.at(i);

        int good_idx = -1;
        int good_val = INT_MAX;
        int sss = group_min.size();
        int flag = 0;
        for (int j = 0; j < sss; j++) {
            int now_val = group_min.at(j);
            if (now_val > num && group_count.at(j) < k && chmin(good_val, now_val)) {
                good_idx = j;
                if (group_count.at(j) == k - 1) {
                    flag = 1;
                } else {
                    flag = 2;
                }
                // break;
            }
            // if (p.at(j) == num) {
            //     group.at(i) = group.at(j);
            //     group_min.at(i) = group_min.at(j);
            //     group_count.at(i) = group_count.at(j);
            //     break;
            // }
        }
        if (flag == 0) {
            //新しい山札を作る
            group.at(num) = current_group;
            group_min.push_back(num);
            group_count.at(current_group) = 1;
            // table.at(num) = make_pair(current_group, 1);
            // group_count.at(current_group)++;
            current_group++;
        } else if (flag == 1) {
            // 山札に積む
            int koko_group = 100;
            group.at(num) = koko_group;
            group_min.at(koko_group) = num;
            group_count.at(koko_group)++;
        } else {
            // 山札を食べる
            int koko_group = 100;
            group.at(num) = koko_group;
            group_count.at(koko_group)++;
            group_min.at(koko_group) = num;
            ans.at(koko_group) = i + 1;
            // table.at(num) = koko;
            // timing.push_back(koko);
        }

        // int place = -1;
        // int good_num = INT_MAX;
        // rep(j, n)
        // {
        //     if (ans.at(j) != -1) {
        //         continue;
        //     }
        // }
    }
    rep(i, n)
    {
        cout << ans.at(group.at(i)) << '\n';
    }
}
