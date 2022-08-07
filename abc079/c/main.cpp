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

// #define endl '\n'

vector<bool> check_seven(vector<int>& abcd, int place, int res, vector<bool> op)
{

    if (place == 3) {
        res += abcd[place];
        if (res == 7) {
            op.at(place) = true;
            op.at(0) = true;
            return op;
        }
        res -= 2 * abcd[place];
        if (res == 7) {
            op.at(0) = true;
            return op;
        }
        return op;
    }
    // if (res == 7 && place == 4) {
    //     return op;
    // }
    res += abcd[place];
    op.at(place) = true;
    op = check_seven(abcd, place + 1, res, op);
    if (op.at(0)) {
        return op;
    }
    res -= 2 * abcd[place];
    op.at(place) = false;
    return check_seven(abcd, place + 1, res, op);
}

int main()
{
    __SPEED_UP__
    // string abcd;
    // cin >> abcd;
    vector<int> abcd;
    rep(i, 4)
    {
        char tmp;
        cin >> tmp;
        abcd.push_back(tmp - '0');
    }
    vector<bool> op;
    op = check_seven(abcd, 1, abcd.at(0), { false, false, false, false });
    cout << abcd.at(0) << (op.at(1) ? '+' : '-') << abcd.at(1) << (op.at(2) ? '+' : '-') << abcd.at(2) << (op.at(3) ? '+' : '-') << abcd.at(3) << "=7" << endl;
}
