#include <bits/stdc++.h>
using namespace std;
using mi = int64_t;
using vmi = vector<mi>;
using vvmi = vector<vmi>;
#define __SPEED_UP__                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define rep(i, n) for (mi i = 0; i < (mi)(n); i++)

void print_vec(vmi vec)
{
    cout << "[ ";
    for (mi i = 0; i < (mi)vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "]" << '\n';
}

int main()
{
    __SPEED_UP__
    mi n;
    cin >> n;
    map<char, mi> int_map;
    map<char, vmi> vec_map;
    auto get_int_value = [&](char value) -> mi {
        if (isdigit(value)) {
            return value - '0';
        } else {
            return int_map.at(value);
        }
    };
    auto get_vec_value = [&]() -> vmi {
        char value;
        cin >> value;
        vmi vec;
        if (value == '[') {
            char op;
            while (true) {
                cin >> value >> op;
                vec.push_back(get_int_value(value));
                if (op == ']') {
                    break;
                }
            }
        } else {
            vec = vec_map.at(value);
        }
        return vec;
    };
    auto calc_int_value = [&](mi int_value) -> mi {
        while (true) {
            char op;
            char value;
            cin >> op;
            if (op == ';') {
                break;
            }
            cin >> value;
            mi op_value;
            op_value = get_int_value(value);
            switch (op) {
            case '+':
                int_value += op_value;
                break;
            case '-':
                int_value -= op_value;
                break;
            case '=':
                int_value = op_value;
                break;
            }
        }
        return int_value;
    };
    auto calc_vec_value = [&](vmi vec_value) -> vmi {
        while (true) {
            char op;
            cin >> op;
            if (op == ';') {
                break;
            }
            vmi op_value;
            op_value = get_vec_value();
            switch (op) {
            case '+':
                rep(i, op_value.size())
                {
                    vec_value.at(i) += op_value.at(i);
                }
                break;
            case '-':
                rep(i, op_value.size())
                {
                    vec_value.at(i) -= op_value.at(i);
                }
                break;
            case '=':
                vec_value = op_value;
                break;
            }
        }
        return vec_value;
    };
    rep(i, n)
    {
        string command;
        cin >> command;
        if (command == "int") {
            char int_name;
            mi int_value = 0;
            cin >> int_name;
            int_map[int_name] = calc_int_value(int_value);
        } else if (command == "print_int") {
            char value;
            cin >> value;
            mi int_value = get_int_value(value);
            int_value = calc_int_value(int_value);
            cout << int_value << '\n';
        } else if (command == "vec") {
            char vec_name;
            vmi vec_value; //引数用に用意（「=」で初期化されるので適当で良い）
            cin >> vec_name;
            vec_map[vec_name] = calc_vec_value(vec_value);
        } else if (command == "print_vec") {
            vmi vec_value = get_vec_value(); // get base vec value
            vec_value = calc_vec_value(vec_value);
            print_vec(vec_value);
        }
    }
}
