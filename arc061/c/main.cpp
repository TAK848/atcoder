#include <bits/stdc++.h>
using namespace std;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define repstep(i, n, step) for (int64_t i = (int64_t)(n); i < (int64_t)(n) + (int64_t)(step); i++)
#define rep2(i, m, n) for (int64_t i = (int64_t)(m); i < (int64_t)(n); i++)
#define repstep2(i, m, n, step) for (int64_t i = (int64_t)(m); i < (int64_t)(n) + (int64_t)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// #define endl '\n'

int64_t str_to_calc(int& n, string& s, vector<bool> add_place)
{
    int64_t ans = 0;
    string tmp = "";
    tmp += s.at(0);
    rep(i, n - 1)
    {
        if (add_place.at(i)) {
            ans += stoll(tmp);
            tmp = "";
            tmp += s.at(i + 1);
        } else {
            tmp += s.at(i + 1);
        }
    }
    ans += stoll(tmp);
    return ans;
}

int64_t calc(int& n, string& s, vector<bool> add_place, int place)
{
    // cout << "place: " << place << endl;
    if (place == n - 1) {
        // cout << "kitaze" << endl;
        // for (auto tf : add_place)
        //     cout << (tf ? "+" : "-");
        // cout << endl;
        return str_to_calc(n, s, add_place);
    }
    int64_t ans = 0;
    string tmp = "";
    // ans += str_to_calc(n, s, add_place);
    ans += calc(n, s, add_place, place + 1);
    add_place.at(place) = true;
    // ans += str_to_calc(n, s, add_place);
    ans += calc(n, s, add_place, place + 1);
    return ans;
}

int main()
{
    __SPEED_UP__
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << s << endl;
        return 0;
    }
    vector<bool> add_place(n - 1, false);
    // n = 3;
    // s = "123";
    // add_place = { false, false };
    // cout << str_to_calc(n, s, add_place) << endl;
    // cout << endl;
    int64_t ans = 0;
    ans += calc(n, s, add_place, 1);
    add_place.at(0) = true;
    ans += calc(n, s, add_place, 1);
    cout << ans << endl;
}
