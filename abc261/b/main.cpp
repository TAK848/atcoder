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
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);
    rep(i, n)
    {
        rep(j, n)
        {
            if (i == j) {
                if (!(s.at(i).at(j) == '-' && s.at(j).at(i) == '-')) {
                    // cout << i + 1 << " " << j + 1 << endl;
                    cout << "incorrect" << endl;
                    return 0;
                }
                continue;
            }
            if (!(s.at(i).at(j) == 'W' && s.at(j).at(i) == 'L')
                && !(s.at(i).at(j) == 'L' && s.at(j).at(i) == 'W')
                && !(s.at(i).at(j) == 'D' && s.at(j).at(i) == 'D')) {
                // cout << i + 1 << " " << j + 1 << " " << s.at(i).at(j) << s.at(j).at(i) << (s.at(i).at(j) == 'D') << endl;
                cout << "incorrect" << endl;
                return 0;
            }
        }
    }
    cout << "correct" << endl;
}
