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

void merge_sort(vector<int> &a, int l, int r)
{
    if (l + 1 >= r)
        return;
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m, r);
    vector<int> b(r - l);
    int i = l, j = m, k = 0;
    while (i < m && j < r)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while (i < m)
        b[k++] = a[i++];
    while (j < r)
        b[k++] = a[j++];
    for (int i = 0; i < k; i++)
        a[l + i] = b[i];
}



int main()
{
    __SPEED_UP__
    int n, q;
    cin >> n >> q;
    string abc;
    rep(i, n)
    {
        abc.push_back((char)('A' + i));
    }
    string ans = abc;

}
