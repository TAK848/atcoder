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
    mi n, m;
    cin >> n >> m;
    set<mi> square_pair;
    rep(i, sqrt(m) + 1)
    {
        if (i * i <= m)
            square_pair.insert(i * i);
    }
    set<pair<mi, mi>> combiation;
    rep(i, sqrt(m) + 2)
    {
        if (square_pair.count(m - i * i)) {
            mi kouho2 = (mi)sqrt(m - i * i);
            mi kouho1 = kouho2 - 1;
            mi kouho3 = kouho2 + 1;
            if (kouho1 * kouho1 + i * i == m) {
                combiation.insert({ kouho1, i });
                combiation.insert({ i, kouho1 });
            } else if (kouho2 * kouho2 + i * i == m) {
                combiation.insert({ kouho2, i });
                combiation.insert({ i, kouho2 });
            } else if (kouho3 * kouho3 + i * i == m) {
                combiation.insert({ kouho3, i });
                combiation.insert({ i, kouho3 });
            }
            // mi cueck = m - i * i;
            // if (i + sqt_num <= n) {
            //     combiation.insert({i, sqt_num});
            // }
            // combiation.insert({ i, (mi)sqrt(m - i * i) });
            // combiation.insert({ (mi)sqrt(m - i * i), i });
            // cout << i << " " << (mi)sqrt(m - i * i) << endl;
        }
    }
    vvmi dp(n, vmi(n, -1));
    dp.at(0).at(0) = 0;
    set<pair<mi, mi>> next;
    next.insert({ 0, 0 });
    rep2(ccc, 1, n * n + 1)
    {
        set<pair<mi, mi>> next_next;
        forallpair(x, y, next)
        {
            // cout << "i, x, y = " << ccc << ", " << x << ", " << y << endl;
            forallpair(i, j, combiation)
            {
                mi xpi, xmi, ypi, ymi, xpj, xmj, ypj, ymj;
                xpi = x + i;
                xmi = x - i;

                ypi = y + i;
                ymi = y - i;
                xpj = x + j;
                xmj = x - j;
                ypj = y + j;
                ymj = y - j;
                if (xpi + 1 > n) {
                    xpi = -1;
                }
                if (xmi < 0) {
                    xmi = -1;
                }
                if (ypi + 1 > n) {
                    ypi = -1;
                }
                if (ymi < 0) {
                    ymi = -1;
                }
                if (xpj + 1 > n) {
                    xpj = -1;
                }
                if (xmj < 0) {
                    xmj = -1;
                }
                if (ypj + 1 > n) {
                    ypj = -1;
                }
                if (ymj < 0) {
                    ymj = -1;
                }
                // cout << "xpi, xmi, ypi, ymi = " << xpi << ", " << xmi << ", " << ypi << ", " << ymi << endl;
                // cout << "xpi,ypj,xpj,ypi,xmi,ymj,xmj,ymi = " << xpi << "," << ypj << "," << xpj << "," << ypi << "," << xmi << "," << ymj << "," << xmj << "," << ymi << endl;
                if (xpi != -1 && ypj != -1 && dp.at(xpi).at(ypj) == -1) {
                    dp.at(xpi).at(ypj) = ccc;
                    next_next.insert({ xpi, ypj });
                }
                if (xpj != -1 && ypi != -1 && dp.at(xpj).at(ypi) == -1) {
                    dp.at(xpj).at(ypi) = ccc;
                    next_next.insert({ xpj, ypi });
                }
                if (xmi != -1 && ymj != -1 && dp.at(xmi).at(ymj) == -1) {
                    dp.at(xmi).at(ymj) = ccc;
                    next_next.insert({ xmi, ymj });
                }
                if (xmj != -1 && ymi != -1 && dp.at(xmj).at(ymi) == -1) {
                    dp.at(xmj).at(ymi) = ccc;
                    next_next.insert({ xmj, ymi });
                }
                if (xpi != -1 && ymj != -1 && dp.at(xpi).at(ymj) == -1) {
                    dp.at(xpi).at(ymj) = ccc;
                    next_next.insert({ xpi, ymj });
                }
                if (xpj != -1 && ymi != -1 && dp.at(xpj).at(ymi) == -1) {
                    dp.at(xpj).at(ymi) = ccc;
                    next_next.insert({ xpj, ymi });
                }
                if (xmi != -1 && ypj != -1 && dp.at(xmi).at(ypj) == -1) {
                    dp.at(xmi).at(ypj) = ccc;
                    next_next.insert({ xmi, ypj });
                }
                if (xmj != -1 && ypi != -1 && dp.at(xmj).at(ypi) == -1) {
                    dp.at(xmj).at(ypi) = ccc;
                    next_next.insert({ xmj, ypi });
                }

                // if (xpi != -1 && ymi != -1 && dp.at(xpi).at(ymi) == -1) {
                //     dp.at(xpi).at(ymi) = i;
                //     next_next.insert({ xpi, ymi });
                // }
                // if (xmi != -1 && ypi != -1 && dp.at(xmi).at(ypi) == -1) {
                //     dp.at(xmi).at(ypi) = i;
                //     next_next.insert({ xmi, ypi });
                // }
                // if (xmi != -1 && ymi != -1 && dp.at(xmi).at(ymi) == -1) {
                //     dp.at(xmi).at(ymi) = i;
                //     next_next.insert({ xmi, ymi });
                // }

                // if (i + j >= n) continue;
                // if (dp.at(i).at(j) == -1) continue;
                // chmax(dp.at(i + 1).at(j), dp.at(i).at(j) + 1);
                // chmax(dp.at(i).at(j + 1), dp.at(i).at(j) + 1);
            }
        }
        next = next_next;
        // next.erase(next.begin(), next.end());
        // next.insert(next_next.begin(), next_next.end());
    }
    forall(i, dp)
    {
        cout << i << endl;
    }
}
