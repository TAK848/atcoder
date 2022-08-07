#include <bits/stdc++.h>
using namespace std;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)
#define repstep(i, n, step) for (mi i = (mi)(n); i < (mi)(n) + (mi)(step); i++)
#define rep2(i, m, n) for (mi i = (mi)(m); i < (mi)(n); i++)
#define repstep2(i, m, n, step) for (mi i = (mi)(m); i < (mi)(n) + (mi)(step); i++)
#define all(v) v.begin(), v.end()
#define YesNo(a) ((a) ? "Yes" : "No")
#define YESNO(a) ((a) ? "YES" : "NO")
#define yesno(a) ((a) ? "yes" : "no")

// // aよりもbが大きいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmax(T& a, const T& b)
// {
//     if (a < b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }
// // aよりもbが小さいならばaをbで更新する
// // (更新されたならばtrueを返す)
// template <typename T>
// bool chmin(T& a, const T& b)
// {
//     if (a > b) {
//         a = b; // aをbで更新
//         return true;
//     }
//     return false;
// }

// #define endl '\n'

// 以下に、24時間表記の時計構造体 Clock を定義する
struct Clock {
    // Clock構造体のメンバ変数を書く
    int hour; // 時間を表す (0~23の値をとる)
    int minute; // 分を表す   (0~59の値をとる)
    int second; // 秒を表す   (0~59の値をとる)
    // メンバ関数 set の定義を書く
    //   関数名: set
    //   引数: int h, int m, int s (それぞれ時、分、秒を表す)
    //   返り値: なし
    //   関数の説明:
    //     時・分・秒を表す3つの引数を受け取り、
    //     それぞれ、メンバ変数 hour, minute, second に代入する
    void set(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    // メンバ関数 to_str の定義を書く
    //   関数名: to_str
    //   引数: なし
    //   返り値: string型
    //   関数の仕様:
    //     メンバ変数が表す時刻の文字列を返す
    //     時刻の文字列は次のフォーマット
    //     "HH:MM:SS"
    //     HH、MM、SSはそれぞれ時間、分、秒を2桁で表した文字列
    string to_str()
    {
        string hs = hour < 10 ? "0" + to_string(hour) : to_string(hour);
        string ms = minute < 10 ? "0" + to_string(minute) : to_string(minute);
        string ss = second < 10 ? "0" + to_string(second) : to_string(second);
        return hs + ":" + ms + ":" + ss;
    }

    // メンバ関数 shift の定義を書く
    //   関数名: shift
    //   引数: int diff_second
    //   返り値: なし
    //   関数の仕様:
    //     diff_second 秒だけメンバ変数が表す時刻を変更する(ただし、日付やうるう秒は考えない)
    //     diff_second の値が負の場合、時刻を戻す
    //     diff_second の値が正の場合、時刻を進める
    //     diff_second の値は -86400 ~ 86400 の範囲を取とりうる
    void shift(int diff_second)
    {
        if (diff_second >= 0) {
            second += diff_second % 60;
        } else {
            second -= -diff_second % 60;
        }
        if (second < 0) {
            second += 60;
            minute--;
        } else if (second > 59) {
            second -= 60;
            minute++;
        }
        if (diff_second >= 0) {
            minute += (diff_second / 60) % 60;
        } else {
            minute -= (-diff_second / 60) % 60;
        }
        if (minute < 0) {
            minute += 60;
            hour--;
        } else if (minute > 59) {
            minute -= 60;
            hour++;
        }

        if (diff_second >= 0) {
            hour += diff_second / 3600;
        } else {
            hour -= -diff_second / 3600;
        }
        if (hour < 0) {
            hour += 24;
        } else if (hour > 23) {
            hour -= 24;
        }
    }
};
// -------------------
// ここから先は変更しない
// -------------------

int main()
{
    __SPEED_UP__
    // 入力を受け取る
    int hour, minute, second;
    cin >> hour >> minute >> second;
    int diff_second;
    cin >> diff_second;

    // Clock構造体のオブジェクトを宣言
    Clock clock;

    // set関数を呼び出して時刻を設定する
    clock.set(hour, minute, second);

    // 時刻を出力
    cout << clock.to_str() << endl;

    // 時計を進める(戻す)
    clock.shift(diff_second);

    // 変更後の時刻を出力
    cout << clock.to_str() << endl;
}
