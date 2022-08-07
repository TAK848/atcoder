import sys

import numpy as np

# from functools import lru_cache


# def main(n):
#     array = np.zeros((n, n), dtype=np.int32)
#     loc_x, loc_y = n // 2, n // 2
#     next_break = 1
#     mode = 1
#     for i in range(1, n ** 2 + 1):
#         array[loc_y, loc_x] = i

#         if i == next_break ** 2:
#             next_break += 1
#             mode = 1 if mode == 2 else 2

#     for i in range(n):
#         print(' '.join(map(str, array[i])))


def main(n):
    array = np.zeros((n, n), dtype=np.int32)
    for i in range(1, n ** 2 + 1):
        if n % 2 == 0:
            array[(i - 1) // n, (i - 1) % n] = i // 2 + \
                1 if i % 2 == 1 else n ** 2 // 2 + (i//2)
        else:

            array[(i - 1) // n, (i - 1) % n] = i // 2 + \
                1 if i % 2 == 1 else n ** 2 // 2 + (i//2+1)
    # direction = 1
    # counter = 0
    # now = n
    # record = 0
    # loc_x, loc_y = 0, 0
    # again = False
    # for i in range(1, n**2+1):
    #     # print(
    #     #     f'in:i {i},now {now},rec {record},dir {direction},x {loc_x},y {loc_y}')
    #     array[loc_x, loc_y] = i + record
    #     if record == 0:
    #         record = ((now ** 2 - (now - 1) ** 2 - 1) // 2)
    #     elif record > 0:
    #         record = record - ((now ** 2 - (now - 1) ** 2 - 1) // 2) - 1
    #     else:
    #         record = record + ((now ** 2 - (now - 1) ** 2 - 1) // 2)
    #     if direction == 1:
    #         loc_x += 1
    #         if loc_x == n - counter:
    #             direction = 2
    #             loc_x -= 1
    #             loc_y += 1
    #         elif array[loc_x, loc_y] != 0:
    #             direction = 2
    #             loc_x -= 1
    #             loc_y += 1
    #     elif direction == 2:
    #         loc_y += 1
    #         if loc_y == n:
    #             direction = 3
    #             loc_y -= 1
    #             loc_x -= 1
    #         elif array[loc_x, loc_y] != 0:
    #             direction = 3
    #             loc_y -= 1
    #             loc_x -= 1
    #     elif direction == 3:
    #         loc_x -= 1
    #         if loc_x == -1:
    #             direction = 4
    #             loc_x += 1
    #             loc_y -= 1
    #         elif array[loc_x, loc_y] != 0:
    #             direction = 4
    #             loc_x += 1
    #             loc_y -= 1
    #     elif direction == 4:
    #         loc_y -= 1
    #         if loc_y == -1:
    #             direction = 1
    #             loc_y += 1
    #             loc_x += 1
    #         elif array[loc_x, loc_y] != 0:
    #             direction = 1
    #             loc_y += 1
    #             loc_x += 1
    #     # print(f'next:{i},{direction},{loc_x},{loc_y}')
    #     if i == now ** 2 - (now - 1) ** 2:
    #         now -= 1
    #         record = 0
    #         # mode = 1 if mode == 2 else 2
    for i in range(n):
        print(' '.join(map(str, array[i])))


def decimal_swap(n):
    return int(str(n)[::-1])


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n = int(lines[0])
    main(n)
