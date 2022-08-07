import sys

# from functools import lru_cache

# import numpy as np


def main(n, k):
    # print(count)
    ans = set()
    if k % 10 == 0:
        if 1 <= k <= n:
            print(1)
            return
        print(0)
        return
    if k > decimal_swap(k):
        print(0)
        return
    if 1 <= k <= n:
        ans.add(k)

    new_num = k
    for j in range(200):
        new_new_num = new_num * 10 ** j
        # print(new_new_num)
        if 1 <= new_new_num <= n:
            ans.add(new_new_num)
    new_num = k
    for i in range(40):
        new_num = decimal_swap(new_num)
        for j in range(200):
            new_new_num = new_num * 10 ** j
            # print(new_new_num)
            if 1 <= new_new_num <= n:
                ans.add(new_new_num)
    # print(ans)
    print(len(ans))
    # print(decimal_swap(k))


# @lru_cache
# def check(k, ans, kaisu):
#     if kaisu == 20:
#         return

#     print('a')


def decimal_swap(n):
    return int(str(n)[::-1])


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, k = [int(x) for x in lines[0].split(' ')]
    main(n, k)
