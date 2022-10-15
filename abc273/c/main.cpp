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
inline ostream& operator<<(ostream& os, vector<T>& vec)
{
    mi size = vec.size();
    rep(i, size) os << vec.at(i) << (i + 1 == size ? "" : " ");
    return os;
}

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    vmi a(n);
    cin >> a;
    vmi bu_a;
    forall(i, a) bu_a.push_back(i);
    sort(all(a), greater<mi>());
    mi bef_v = a.at(0);
    vmi aaa(n);
    aaa.at(0) = 0;
    rep2(i, 1, n)
    {
        mi v = a.at(i);
        if (v == bef_v) {
            aaa.at(i) = aaa.at(i - 1);
        } else {
            aaa.at(i) = aaa.at(i - 1) + 1;
        }
        bef_v = v;
        // cout << i << " " << v << " " << aaa.at(i) << endl;
        // cout << i << endl;
        // bef_v = i;
    }
    vmi ans(n);
    forall(i, aaa)
    {
        ans.at(i)++;
    }
    forall(i, ans)
    {
        cout << i << endl;
    }
    // map<mi, mi> mp;
    // vmi ans(n);
    // mi bef = 0;
    // forall(i, a)
    // {
    //     mp[i] = bef + 1;
    //     bef++;
    //     cout << i << " " << bef << endl;
    //     //     mi idx = n-i-1;
    //     //     if(idx!=n-1){

    //     //     }
    //     // mi cnt = 0;
    //     // for(mi j = 0; j < n; j++) {
    //     //     if(a.at(j) % i == 0) {
    //     //         cnt++;
    //     //     }
    //     // }
    //     // if(cnt >= 2) {
    //     //     mp[i] = cnt;
    //     // }
    //     // }
    // }
    // map<mi, mi> ansmap;
    // rep(i, n)
    // {
    //     ansmap[i] = 0;
    // }
    // forall(i, bu_a)
    // {
    //     // cout << mp[i] << endl;
    //     // if(ansmap.count(mp[i]) == 0) {
    //     //     ansmap[mp[i]] = 1;
    //     // } else {
    //     ansmap[mp[i]]++;
    //     // }
    // }
    // rep(i, n)
    // {
    //     cout << ansmap[i] << endl;
    // }
}
