#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repstep(i, n, step) for (int i = (int)(n); i < (int)(n) + (int)(step); i++)
#define rep2(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define repstep2(i, m, n, step) for (int i = (int)(m); i < (int)(n) + (int)(step); i++)
// #define endl '\n'

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int num = 1;
    repstep2(i, 1, s.size(), 2)
    {
        // if (i % 2 == 1) {
        switch (s[i]) {
        case '+':
            num++;
            break;
        case '-':
            num--;
            break;
        }
        // }
    }
    cout << num << '\n';
}
