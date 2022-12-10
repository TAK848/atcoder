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
    mi n, m, k;
    cin >> n >> m >> k;
    vmi a(n);
    cin >> a;

    priority_queue<mi> que;
    mi sum = 0;
    mi msum = 0;
    map<mi, mi> mp;
    rep(i, k)
    {
        // que.push(a.at(i));
        // sum += a.at(i);
        mp[a.at(i)]++;
    }
    // msum = sum;

    rep2(i, k, m)
    {
        // que.push(a.at(i));
        // sum += a.at(i);
        // msum += a.at(i);
        // sum -= que.top();
        // que.pop();
        mp[a.at(i)]++;

        // auto [key, val] = *mp.begin();
        // cout << i << " " << que.size() << " " << sum << endl;
    }
    mi counter = 0;
    mi minkey = mp.begin()->first;
    mi maxrangekey, maxrangecount;
    mi maxkey = mp.rbegin()->first;
    forallpair(key, val, mp)
    {
        // cout << key << " " << val << endl;
        if (counter + val < k) {
            sum += key * val;
            maxrangekey = key;
            maxrangecount = val;
        } else {
            sum += key * (k - counter);
            maxrangekey = key;
            maxrangecount = k - counter;
            break;
        }
        counter += val;
    }
    cout << sum << (m == n ? " " : " ");
    rep2(i, m, n)
    {
        mi newnumber = a.at(i);
        // cout << "new " << newnumber << " minkey " << minkey << " maxrangekey " << maxrangekey << " maxrangecount " << maxrangecount << endl;
        mp[newnumber]++;
        if (minkey > newnumber) {
            minkey = newnumber;
            sum += newnumber;
            // if (maxrangecount == 1) {
            //     mi index = maxrangekey;

            // }
            // remove 1 maxrangekey
            // mp[maxrangekey]--;
            maxrangecount--;
            sum -= maxrangekey;
            if (maxrangecount == 0) {
                auto previtr = prev(mp.find(maxrangekey));
                // mp.erase(maxrangekey);
                maxrangekey = previtr->first;
                maxrangecount = previtr->second;
                // cout << "prev " << previtr->first << " " << previtr->second << endl;
            }
        } else if (maxrangekey > newnumber) {
            sum += newnumber;
            sum -= maxrangekey;
            // mp[maxrangekey]--;
            maxrangecount--;
            if (maxrangecount == 0) {
                // mp.erase(maxrangekey);
                auto previtr = prev(mp.find(maxrangekey));
                maxrangekey = previtr->first;
                maxrangecount = previtr->second;
            }
        } else {
            // sum += newnumber;
        }
        // cout << "newsumx " << sum << endl;
        mi rmnumber = a.at(i - m);
        // cout << "remove " << rmnumber << endl;
        auto maxnextitr = next(mp.find(maxrangekey));
        auto minnextitr = next(mp.find(minkey));

        if (rmnumber > maxrangekey) {
            mp[rmnumber]--;
            if (mp[rmnumber] == 0) {
                mp.erase(rmnumber);
            }
        } else if (rmnumber == minkey) {
            mp[rmnumber]--;
            sum -= rmnumber;
            if (mp[rmnumber] == 0) {
                mp.erase(rmnumber);
                minkey = minnextitr->first;
            }

            // sum += minkey;
            mi maxrangeval = mp[maxrangekey];
            if (maxrangeval > maxrangecount) {
                maxrangecount++;
                sum += maxrangekey;
            } else {
                maxrangekey = maxnextitr->first;
                maxrangecount = 1;
                sum += maxrangekey;
            }

        } else if (rmnumber == maxrangekey) {
            mp[rmnumber]--;
            sum -= rmnumber;
            if (mp[rmnumber] == 0) {
                maxrangekey = maxnextitr->first;
                maxrangecount = 1;
                mp.erase(rmnumber);
            }
            sum += maxrangekey;
        } else {
            mp[rmnumber]--;
            sum -= rmnumber;
            if (mp[rmnumber] == 0) {
                mp.erase(rmnumber);
            }

            maxrangecount++;
            if (maxrangecount > mp[maxrangekey]) {
                // mp.erase(maxrangekey);
                maxrangekey = maxnextitr->first;
                maxrangecount = maxnextitr->second;
            }
            sum += maxrangekey;

            // sum += minkey;
            // mi maxrangeval = mp[maxrangekey];
            // if (maxrangeval > maxrangecount) {
            //     maxrangecount++;
            //     sum += maxrangekey;
            // } else {
            //     maxrangekey = maxnextitr->first;
            //     maxrangecount = maxnextitr->second;
            //     sum += maxrangekey;
            // }
        }
        // cout << "newsum " << sum << endl;
        cout << sum << (i + 1 == n ? "\n" : " ");

        // mp[rmnumber]--;
        // if (mp[rmnumber] == 0) {
        //     mp.erase(rmnumber);
        // }
        // if (rmnumber == minkey) {
        //     auto [key, val] = *mp.begin();
        //     minkey = key;
        // }
        // if (rmnumber == maxkey) {
        //     maxcount--;
        //     if (maxcount == 0) {
        //         auto [key, val] = *mp.rbegin();
        //         maxkey = key;
        //         maxcount = val;
        //     }
        // }

        // que.push(a.at(i));
        // sum += a.at(i);
        // sum -= que.top();
        // que.pop();
        // cout << i << " " << que.size() << " " << sum << endl;
        // cout << sum << (i + 1 == n ? "\n" : " ");
        // mp[a.at(i)]++;
    }
    // forallpair(key, val, mp)
    // {
    //     cout << key << " " << val << endl;
    // }
}
