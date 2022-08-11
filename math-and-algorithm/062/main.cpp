#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
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
    mi n, k;
    cin >> n >> k;
    vmi a(n);
    rep(i, n)
    {
        cin >> a.at(i);
        a.at(i)--;
    }
    vmi lis;
    mi next = 0;
    lis.push_back(0);
    vmi visited(n, -1);
    mi c = 0;
    visited.at(0) = c;
    while (true) {
        // cout << "a" << next << endl;
        next = a.at(next);
        if (visited.at(next) != -1) {
            break;
        }
        lis.push_back(next);
        c++;
        visited.at(next) = c;
        // cout << c++ << endl;
    }
    // cout << "a" << next << endl;
    mi size = lis.size();
    // cout << size << " " << next << endl;
    if (k < size) {
        cout << lis.at(k) + 1 << '\n';
        return 0;
    }
    mi bef_roop_dist = next == 0 ? 0 : distance(a.begin(), find(all(a), next));
    bef_roop_dist = visited.at(next);
    mi roop_size = size - bef_roop_dist;
    mi index = (k - bef_roop_dist) % roop_size + bef_roop_dist;
    // cout << size << " " << bef_roop_dist << " " << roop_size << " " << index << '\n'
    //      << endl;
    // cout << "a" << next << endl;
    cout << lis.at(index) + 1 << '\n';
}
