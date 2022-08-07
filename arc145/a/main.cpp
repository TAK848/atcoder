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
    string s;
    cin >> n >> s;
    if (s.at(0) == 'A' && s.at(n - 1) == 'B') {
        cout << "No" << '\n';
        return 0;
    }
    if (n % 2 == 1) {
        cout << "Yes" << '\n';
        return 0;
    }
    int start = 0;
    int end = n - 1;
    // int lastplace = 0;
    while (start + 1 != end) {
        // cout << start << " " << end << " " << s << endl;
        if (s.at(start) == 'A' && s.at(end) == 'B') {
            if (s.at(start - 1) == 'B') {
                if (s.at(end + 1) == 'B') {
                    s.at(end) = 'A';
                }
                // cout << "No" << '\n';
                // return 0;
            } else {
                s.at(start) = 'B';
            }
        }
        if (s.at(start) == 'B' && s.at(end) == 'A') {
            // s.at(start) = 'A';
            // s.at(start + 1) = 'B';
            if (s.at(start + 1) == 'B' && s.at(end - 1) == 'B') {
                s.at(start) = 'A';
            } else if (s.at(start + 1) == 'A' && s.at(end - 1) == 'A') {
                s.at(end) = 'B';
            } else {
                s.at(end) = 'B';
                s.at(end - 1) = 'A';
                // cout << "waaaaa" << '\n';
            }
            // if (s.at(start - 1) == 'A') {
            //     if (s.at(end + 1) == 'A') {
            //         s.at(end) = 'B';
            //     }
            //     // cout << "No" << '\n';
            //     // return 0;
            // } else {
            //     s.at(start) = 'A';
            // }
            // if (start + 1 == end) {
            //     cout << "No" << '\n';
            //     return 0;
            // } else
            // if (s.at(end - 1) == 'A') {
            //     s.at(end) = 'B';
            // } else {
            //     s.at(start) = 'A';
            //     s.at(start + 1) = 'B';
            // }
        }
        start++;
        end--;
    }
    // cout << start << " " << end << " " << s << endl;
    if (s.at(start) == s.at(end)) {
        cout << "Yes" << '\n';
    } else {
        if (s.at(start) == 'A' && s.at(end) == 'B') {
            cout << "Yes" << '\n';
        } else {
            if (s == "BA") {
                cout << "No" << '\n';
                return 0;
            }
            cout << "Yes" << '\n';
        }
    }
}
