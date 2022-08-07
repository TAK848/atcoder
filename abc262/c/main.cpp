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
    int64_t n;
    cin >> n;
    vector<int64_t> a(n);
    int64_t same_count = 0;
    rep(i, n)
    {
        int b;
        cin >> b;
        a.at(i) = b - 1;
        // if (b - 1 == i) {
        //     same_count++;
        // }
        // cout << a.at(i) << " ";
    }
    // cout << endl;
    int64_t mix_count = 0;
    rep(i, n)
    {
        if (a.at(i) == i) {
            same_count++;
        } else if (a.at(a.at(i)) == i) {
            mix_count++;
        }
    }
    // cout << same_count << " " << mix_count << endl;
    cout << (same_count * (same_count - 1)) / 2 + (mix_count / 2) << endl;
}
