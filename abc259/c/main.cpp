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

int main()
{
    __SPEED_UP__
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int t_index = 0;
    int s_index = 0;
    char checking = ' ';
    int count = 0;
    bool flag = true;
    int s_count, t_count;
    while (flag) {
        s_count = 0;
        checking = s.at(s_index);
        while (true) {

            if (s.at(s_index) == checking) {
                // cout << "checking: " << checking << s_index << s_count << endl;
                s_count++;
                s_index++;
                if (s_index == n) {
                    flag = false;
                    // if(t_index == m - 1){
                    // cout << "" << endl;
                    // }
                    break;
                }

            } else {
                // cout << "checkingx: " << checking << s_index << s_count << endl;
                // s_index--;
                break;
            }
        }

        t_count = 0;
        while (true) {
            // cout << t.at(t_index) << checking << s_index << s_count << t_index << t_count << '\n';
            if (t.at(t_index) == checking) {
                t_count++;
                t_index++;
                if (t_index == m) {
                    if (flag) {
                        cout << "No" << '\n';
                        return 0;
                    }
                    flag = false;
                    break;
                }
            } else {
                // t_index++;
                if (t_count == 0) {
                    cout << "No" << '\n';
                    return 0;
                } else if (s_count == 1) {
                    if (t_count == 1) {
                        // cout << "YES" << '\n';
                        break;
                    } else {
                        // cout << checking << s_index << s_count << t_index << t_count << '\n';
                        cout << "No" << '\n';
                        return 0;
                    }
                    // cout << "NO" << '\n';
                    // break;
                } else if (s_count > t_count) {
                    cout << "No" << '\n';
                    return 0;
                }
                break;
            }
        }
        // if (!flag) {

        //     if (s_count != t_count) {
        //         cout << "No" << '\n';
        //         return 0;
        //     }
        // }
    }
    if (t_index != m) {
        cout << "No" << '\n';
        return 0;
    }
    if (t_count == 0) {
        cout << "No" << '\n';
        return 0;
    } else if (s_count == 1) {
        if (t_count == 1) {
            // cout << "YES" << '\n';
            // break;
        } else {
            // cout << checking << s_index << s_count << t_index << t_count << '\n';
            cout << "No" << '\n';
            return 0;
        }
        // cout << "NO" << '\n';
        // break;
    } else if (s_count > t_count) {
        cout << "No" << '\n';
        return 0;
    }

    // rep(i, n)
    // {
    //     if (s.at(i) == checking) {
    //         count++;
    //         if (!(i + 1 == n)) {
    //             if (s.at(i + 1) == checking) {
    //                 continue;
    //             }
    //         }
    //         bool once = false;
    //         int count2 = 0;
    //         while (t_index < m) {
    //             if (t.at(t_index) == checking) {
    //                 once = true;
    //                 count2++;
    //                 // if (t.at(t_index + 1) == checking) {
    //                 //     t_index++;
    //                 //     continue;
    //                 // } else {
    //                 //     break;
    //                 // }
    //                 t_index++;
    //             } else {
    //                 if (count2 == 0 || count2 < count) {
    //                     cout << "No" << '\n';
    //                     return 0;
    //                 }
    //                 break;
    //             }
    //         }
    //         if (t_index == m && t.at(m - 1) != checking) {
    //             cout << "No" << '\n';
    //             return 0;
    //         }
    //         //ここに処理をかく
    //         // t_index++;
    //     } else {
    //         cout << checking << count << '\n';

    //         checking = s.at(i);
    //         count = 0;
    //         // t_index = 1;
    //         // cout << "No" << '\n';
    //         // return 0;
    //     }
    //     if (s.at(i) == t.at(t_index)) {
    //         t_index++;
    //     }
    // }
    cout << "Yes" << '\n';
}
