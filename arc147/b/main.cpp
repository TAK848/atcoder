#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vvs = vector<vs>;
using vb = vector<bool>;
using vvb = vector<vb>;
// using modi = modint1000000007;
// using modi = modint998244353;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)
#define repstep(i, n, step) for (mi i = (mi)(n); i < (mi)(n) + (mi)(step); i++)
#define rep2(i, m, n) for (mi i = (mi)(m); i < (mi)(n); i++)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
#define forall(i, v) for (auto& i : v)
#define forallpair(i, j, v) for (auto& [i, j] : v)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// aよりもbが大きいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
inline bool chmax(T& a, T b) { return ((a < b) ? (a = b, true) : (false)); }
// aよりもbが小さいならばaをbで更新する(更新されたならばtrueを返す)
template <typename T>
inline bool chmin(T& a, T b) { return ((a > b) ? (a = b, true) : (false)); }
template <typename T>
inline istream& operator>>(istream& is, vector<T>& vec)
{
    for (T& x : vec)
        is >> x;
    return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    }
    return os;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vmi p(n);
    cin >> p;
    vmi x(n);
    // rep(i, n) x.at(i) = p.at(i) % 2;
    mi ans = 0;
    string ansstr = "";
    // rep(i, n)
    // {
    //     if (p.at(i) % 2 == ((i + 1) % 2)) {

    //     } else {
    //         // ans++;
    //     }
    //     cout << p << endl;
    // }
    // cout << ans << endl;
    if (n == 2) {
        if (p.at(0) == 2 && p.at(1) == 1) {
            cout << "1\nA 1\n";
        } else {
            cout << 0 << endl;
        }
        return 0;
    }

    rep(_, n * n)
        rep(i, n - 2)
    {
        bool flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        // cout << i << " " << p << " " << flag1 << flag2 << flag3 << endl;
        if (!flag1 && !flag2) {
            if (p.at(i) > p.at(i + 1)) {
                swap(p.at(i), p.at(i + 1));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 1) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        if (!flag2 && !flag3) {
            if (p.at(i + 1) > p.at(i + 2)) {
                swap(p.at(i + 1), p.at(i + 2));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 2) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        if (p.at(i) > p.at(i + 2)) {
            swap(p.at(i), p.at(i + 2));
            ans++;
            // cout << "B " << i + 1 << endl;
            ansstr += "B " + to_string(i + 1) + "\n";

            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        // mi ppp = n - 3;
        // while (i < ppp) {
        //     if ((flag1 == !flag2 && !flag2 == flag3)) {
        //     }
        // }
        if ((flag1 == !flag2 && !flag2 == flag3) && i < n - 3) {
            bool flag4 = p.at(i + 3) % 2 == (i + 4) % 2;
            // if (p.at(i + 1) > p.at(i + 3)) {
            swap(p.at(i + 1), p.at(i + 3));
            ans++;
            // cout << "B " << i + 1 << endl;
            ansstr += "B " + to_string(i + 2) + "\n";
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
            // }
        }
        // if()
        if (!flag1 && !flag2) {
            if (p.at(i) > p.at(i + 1)) {
                swap(p.at(i), p.at(i + 1));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 1) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        if (!flag2 && !flag3) {
            if (p.at(i + 1) > p.at(i + 2)) {
                swap(p.at(i + 1), p.at(i + 2));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 2) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
    }

    rep(_, n * n)
    {
        rep(i, n - 2)
        {

            if (p.at(i) > p.at(i + 2)) {
                swap(p.at(i), p.at(i + 2));
                ans++;
                // cout << "B " << i + 1 << endl;
                ansstr += "B " + to_string(i + 1) + "\n";
            }
        }
    }

    rep(_, n * n)
        rep(i, n - 2)
    {
        bool flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        // cout << i << " " << p << " " << flag1 << flag2 << flag3 << endl;
        if (!flag1 && !flag2) {
            if (p.at(i) > p.at(i + 1)) {
                swap(p.at(i), p.at(i + 1));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 1) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        if (!flag2 && !flag3) {
            if (p.at(i + 1) > p.at(i + 2)) {
                swap(p.at(i + 1), p.at(i + 2));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 2) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        if (p.at(i) > p.at(i + 2)) {
            swap(p.at(i), p.at(i + 2));
            ans++;
            // cout << "B " << i + 1 << endl;
            ansstr += "B " + to_string(i + 1) + "\n";

            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        // mi ppp = n - 3;
        // while (i < ppp) {
        //     if ((flag1 == !flag2 && !flag2 == flag3)) {
        //     }
        // }
        if ((flag1 == !flag2 && !flag2 == flag3) && i < n - 3 && p.at(i + 1) > p.at(i + 3)) {
            bool flag4 = p.at(i + 3) % 2 == (i + 4) % 2;
            // if (p.at(i + 1) > p.at(i + 3)) {
            swap(p.at(i + 1), p.at(i + 3));
            ans++;
            // cout << "B " << i + 1 << endl;
            ansstr += "B " + to_string(i + 2) + "\n";
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
            // }
        }
        // if()
        if (!flag1 && !flag2) {
            if (p.at(i) > p.at(i + 1)) {
                swap(p.at(i), p.at(i + 1));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 1) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
        if (!flag2 && !flag3) {
            if (p.at(i + 1) > p.at(i + 2)) {
                swap(p.at(i + 1), p.at(i + 2));
                ans++;
                // cout << "A " << i + 1 << endl;
                ansstr += "A " + to_string(i + 2) + "\n";
            }
            flag1 = p.at(i) % 2 == (i + 1) % 2, flag2 = p.at(i + 1) % 2 == (i + 2) % 2, flag3 = p.at(i + 2) % 2 == (i + 3) % 2;
        }
    }

    cout << ans << endl;
    cout << ansstr;
    cout << p << endl;
    // rep(i, n)
    // {
    //     cout << p.at(i) << endl;
    // }
}
