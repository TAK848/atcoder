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
int64_t n, x, y;

bool sousa1(vector<int64_t>& red, vector<int64_t>& blue, int64_t step)
{
    if (step == 0) {
        return false;
    }
    int64_t count = red.at(step);
    red.at(step) = 0;
    blue.at(step) += count * x;
    red.at(step - 1) += count;
    return true;
}
bool sousa2(vector<int64_t>& red, vector<int64_t>& blue, int64_t step)
{
    if (step == 0) {
        return false;
    }
    int64_t count = blue.at(step);
    blue.at(step) = 0;
    blue.at(step - 1) += (count * y);
    red.at(step - 1) += count;
    return true;
}
void debug_print64_t(vector<int64_t>& red, vector<int64_t>& blue)
{
    rep(i, n)
    {
        cout << red.at(i) << " ";
    }
    cout << endl;
    rep(i, n)
    {
        cout << blue.at(i) << " ";
    }
    cout << endl
         << endl;
}

int main()
{
    __SPEED_UP__
    cin >> n >> x >> y;
    vector<int64_t> red(n, 0), blue(n, 0);
    red.at(n - 1) = 1;
    // debug_print64_t(red, blue);
    for (int64_t i = n - 1; i >= 0; i--) {
        sousa1(red, blue, i);
        // debug_print64_t(red, blue);
        sousa2(red, blue, i);
        // debug_print64_t(red, blue);
        // cin>> red.at(i);
    }
    cout << blue.at(0) << "\n";
}
