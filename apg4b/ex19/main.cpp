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
#define endl '\n'
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// 参照渡しを用いて、呼び出し側の変数の値を変更する
void saiten(vector<vector<int>>& a, int& correct_count, int& wrong_count)
{
    // 呼び出し側のAの各マスを正しい値に修正する
    // Aのうち、正しい値の書かれたマスの個数を correct_count に入れる
    // Aのうち、誤った値の書かれたマスの個数を wrong_count に入れる

    // ここにプログラムを追記
    int ans;
    rep(i, 9)
    {
        rep(j, 9)
        {
            ans = (i + 1) * (j + 1);
            if (a.at(i).at(j) == ans)
                correct_count++;
            else {
                wrong_count++;
                a.at(i).at(j) = ans;
            }
        }
    }
}

// -------------------
// ここから先は変更しない
// -------------------
int main()
{
    __SPEED_UP__
    // A君の回答を受け取る
    vector<vector<int>> A(9, vector<int>(9));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> A.at(i).at(j);
        }
    }

    int correct_count = 0; // ここに正しい値のマスの個数を入れる
    int wrong_count = 0; // ここに誤った値のマスの個数を入れる

    // A, correct_count, wrong_countを参照渡し
    saiten(A, correct_count, wrong_count);

    // 正しく修正した表を出力
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << A.at(i).at(j);
            if (j < 8)
                cout << " ";
            else
                cout << endl;
        }
    }
    // 正しいマスの個数を出力
    cout << correct_count << endl;
    // 誤っているマスの個数を出力
    cout << wrong_count << endl;
}
