#include <bits/stdc++.h>
using namespace std;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)
#define repstep(i, n, step) for (mi i = (mi)(n); i < (mi)(n) + (mi)(step); i++)
#define rep2(i, m, n) for (mi i = (mi)(m); i < (mi)(n); i++)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// // aよりもbが大きいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmax(T& a, const T& b)
// {
//     if (a < b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }
// // aよりもbが小さいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmin(T& a, const T& b)
// {
//     if (a > b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }

// #define endl '\n'

int main()
{
    __SPEED_UP__
    string s;
    cin >> s;
    mi size = s.size();
    string tmp;
    rep(i, size)
    {
        tmp += s.at(i);
        // cout << tmp << '\n';
        if (tmp.size() == 5) {
            if (tmp == "dream") {
                if (i + 2 < size) {
                    if (s.at(i + 1) == 'e' && s.at(i + 2) == 'r') {
                        // i += 2;
                        if (i + 3 < size) {
                            if (s.at(i + 3) != 'a') {
                                i += 2;
                            }
                        } else {
                            i += 2;
                        }
                    }
                }
                tmp = "";
            } else if (tmp == "erase") {
                if (i + 1 < size) {
                    if (s.at(i + 1) == 'r') {
                        i++;
                    }
                }
                tmp = "";
            } else {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    cout << (tmp.size() == 0 ? "YES" : "NO") << '\n';
}
