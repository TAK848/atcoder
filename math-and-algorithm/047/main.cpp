#include <atcoder/all>
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using namespace atcoder;
using mi = int;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)

int main()
{
    __SPEED_UP__
    mi n, m;
    cin >> n >> m;
    vvmi g(n, vmi());
    rep(i, m)
    {
        mi a, b;
        cin >> a >> b;
        g.at(a - 1).push_back(b - 1);
        g.at(b - 1).push_back(a - 1);
    }
    queue<mi> q;
    vmi d(n, -1);
    rep(j, n)
    {
        if (d.at(j) == -1) {
            q.push(j);
            d.at(j) = 0;
        }
        while (!q.empty()) {
            mi u = q.front();
            q.pop();
            rep(i, g.at(u).size())
            {
                mi v = g.at(u).at(i);
                if (d.at(v) == -1) {
                    d.at(v) = d.at(u) + 1;
                    q.push(v);
                } else {
                    if (d.at(v) % 2 == d.at(u) % 2) {
                        cout << "No" << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << '\n';
}
