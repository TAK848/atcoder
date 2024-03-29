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

// 各操作を行う関数を実装する

// AとBに共通して含まれる要素からなる集合を返す
bitset<50> intersection(bitset<50> A, bitset<50> B)
{
    return A & B;
}
// AとBのうち少なくとも一方に含まれる要素からなる集合を返す
bitset<50> union_set(bitset<50> A, bitset<50> B)
{
    return A | B;
}
// AとBのうちどちらか一方にだけ含まれる要素からなる集合を返す
bitset<50> symmetric_diff(bitset<50> A, bitset<50> B)
{
    return A ^ B;
}
// Aから値xを除く
bitset<50> subtract(bitset<50> A, int x)
{
    return A.reset(x);
}
// Aに含まれる要素に1を加える(ただし、要素49が含まれる場合は0になるものとする)
bitset<50> increment(bitset<50> A)
{
    if (A.test(49)) {
        A <<= 1;
        A.set(0);
    } else {
        A <<= 1;
    }
    return A;
}
// Aに含まれる要素から1を引く(ただし、要素0が含まれる場合は49になるものとする)
bitset<50> decrement(bitset<50> A)
{
    if (A.test(0)) {
        A >>= 1;
        A.set(49);
    } else {
        A >>= 1;
    }
    return A;
}

// Sに値xを加える
bitset<50> add(bitset<50> S, int x)
{
    S.set(x, 1); // xビット目を1にする
    return S;
}

// 集合Sの内容を昇順で出力する(スペース区切りで各要素の値を出力する)
void print_set(bitset<50> S)
{
    vector<int> cont;
    for (int i = 0; i < 50; i++) {
        if (S.test(i)) {
            cont.push_back(i);
        }
    }
    for (int i = 0; i < cont.size(); i++) {
        if (i > 0)
            cout << " ";
        cout << cont.at(i);
    }
    cout << endl;
}

// これより下は書き換えない

int main()
{
    __SPEED_UP__

    bitset<50> A, B;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        A = add(A, x);
    }
    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        B = add(B, x);
    }

    // 操作
    string com;
    cin >> com;

    if (com == "intersection") {
        print_set(intersection(A, B));
    } else if (com == "union_set") {
        print_set(union_set(A, B));
    } else if (com == "symmetric_diff") {
        print_set(symmetric_diff(A, B));
    } else if (com == "subtract") {
        int x;
        cin >> x;
        print_set(subtract(A, x));
    } else if (com == "increment") {
        print_set(increment(A));
    } else if (com == "decrement") {
        print_set(decrement(A));
    }
}
