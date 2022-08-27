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

// #define endl '\n'

int main()
{
    __SPEED_UP__
    mi ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    // mi ac2, bd2;
    // ac2 = (ax - cx) * (ax - cx) + (ay - cy) * (ay - cy);
    // bd2 = (bx - dx) * (bx - dx) + (by - dy) * (by - dy);
    // mi ab2, bc2, cd2, da2;
    // ab2 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
    // bc2 = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
    // cd2 = (cx - dx) * (cx - dx) + (cy - dy) * (cy - dy);
    // da2 = (dx - ax) * (dx - ax) + (dy - ay) * (dy - ay);
    // mi outer_product_
    mi acx, acy, bdx, bdy;
    acx = cx - ax;
    acy = cy - ay;
    bdx = dx - bx;
    bdy = dy - by;
    mi abx, aby, adx, ady;
    abx = bx - ax;
    aby = by - ay;
    adx = dx - ax;
    ady = dy - ay;
    mi bax, bay, bcx, bcy;
    bax = ax - bx;
    bay = ay - by;
    bcx = cx - bx;
    bcy = cy - by;
    mi crossacb = acx * aby - acy * abx;
    mi crossacd = acx * ady - acy * adx;
    mi crossbda = bdx * bay - bdy * bax;
    mi crossbdc = bdx * bcy - bdy * bcx;
    if (crossacb * crossacd < 0 && crossbda * crossbdc < 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
