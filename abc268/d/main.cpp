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
vector<pair<string, mi>> encode(vs& str)
{
    mi n = str.size();
    vector<pair<string, mi>> ret;
    rep(l, n)
    {
        mi r = l + 1;
        for (; r < n && str[l] == str[r]; r++) { };
        ret.push_back({ str[l], r - l });
        l = r;
    }
    return ret;
}

mi n, m;
set<string> st;
void rec(string s, vs& sv, mi step)
{
    // cout << step << " " << s << endl;
    if (step == 2 * n - 1) {
        return;
    }
    if (s.size() > 16) {
        // if (step != 2 * (n - 1) + 1) {
        // return;
        // }
        while (s.back() == '_') {
            s.pop_back();
        }
        if (16 >= s.size() && s.size() >= 3 && !st.count(s) && step == 2 * (n - 1) + 1) {
            // return s;
            cout << s << endl;
            // cout << "yeah2     " << s << endl;
            exit(0);
        }
        return;
    }
    if (step >= 5 && s.at(s.size() - 1) != '_') {
        if (s.size() >= 3 && !st.count(s) && step == 2 * (n - 1)) {
            // return s;
            cout << s << endl;
            // cout << "yeah     " << s << endl;
            exit(0);
        }
    }
    // cout << "koeta" << endl;
    if (step % 2 == 0) {
        // st.insert(sv);
        // return;
        // s = s + sv.at(step / 2);
        // s + rec(s, sv, step + 1);
        // cout << s + sv.at(step / 2) << endl;
        if (step / 2 >= n || (s.size() + sv.at(step / 2).size()) > 16) {
            return;
        }
        rec(s + sv.at(step / 2), sv, step + 1);
    } else if (s.at(s.size() - 1) == '_') {
        // s = s + "_";
        rec(s + "_", sv, step + 0);
        rec(s + "_", sv, step + 1);

        // } else {
        // s = s + "_";
        // s + rec(s, sv, step);
        // rec(s + "_", sv, step + 0);
        // rec(s + "_", sv, step + 1);
    }
    return;
}

int main()
{
    __SPEED_UP__
    cin >> n >> m;
    // map<string, pair<mi, mi>> mp;
    // rep(i, n)
    // {
    //     string s;
    //     cin >> s;
    //     mp[s].first = s.size();
    //     mp[s].second++;
    // }
    // sort(all(mp), [](const pair<string, pair<mi, mi>>& a, const pair<string, pair<mi, mi>>& b) {
    //     return a.second.first > b.second.first;
    // });
    vs s(n);
    cin >> s;
    rep(i, m)
    {
        string t;
        cin >> t;
        st.insert(t);
    }
    // vs t(n);
    // cin >> t;
    // vvs spl(n);

    // rep(i, n)
    // {
    //     stringstream ss { t.at(i) };
    //     string buf;
    //     while (getline(ss, buf, '_')) {
    //         spl.at(i).push_back(buf);
    //     }
    //     cout << spl.at(i) << endl;
    // }
    // vector<vector<pair<string, mi>>> enc(n);
    // rep(i, n)
    // {
    //     enc.at(i) = encode(spl.at(i));
    // }
    // sort(enc);
    // rep(i, n)
    // {

    //     forallpair(sss, jjj, enc.at(i))
    //     {
    //         cout << sss << " " << jjj;
    //     }
    //     cout << endl;
    // }

    vmi l(n);
    rep(i, n) l.at(i) = s.at(i).size();
    sort(all(s));
    do {
        string t;
        // rep(i, n)
        {
            // t += s.at(i);
            rec(t, s, 0);
            // if (t != "") {
            // cout << t << endl;
            // return 0;
            // }
        }
        // cout << s << endl;
        // rep
        // mi count = 0;
        // forall(vpenc, enc)
        // {
        // }

    } while (next_permutation(all(s)));
    cout << -1 << endl;
}
