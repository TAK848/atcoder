import sys

import numpy as np


def main(n, A):
    # print(n, A)
    maxnum = 0
    for i in range(n):
        for j in range(n):
            new = ''
            new2 = ''
            new3 = ''
            new4 = ''
            new5 = ''
            new6 = ''
            new7 = ''
            new8 = ''
            for start in range(n):
                new += A[i][(start + j) % n]
                new2 += A[(start + j) % n][i]
                new3 += A[i][(j - start) % n]
                new4 += A[(j - start) % n][i]
                new5 += A[(i + start) % n][(j + start) % n]
                new6 += A[(i + start) % n][(j - start) % n]
                new7 += A[(i - start) % n][(j + start) % n]
                new8 += A[(i - start) % n][(j - start) % n]

            maxnum = max(maxnum, int(new), int(new2), int(new3), int(
                new4), int(new5), int(new6), int(new7), int(new8))
    print(maxnum)
    # count = 0
    # array = np.full(2 * (10 ** 5) + 1, False, dtype=bool)
    # # print(rans)
    # for ran in rans:
    #     array[ran[0]:ran[1]] = True
    #     # print(ran)
    #     # print(array[ran[0]:ran[1]])
    # flag = False
    # # print(array[10:20])
    # bu = 0
    # for index, result in enumerate(array):
    #     # print(result)
    #     if not flag and result:
    #         flag = True
    #         bu = index
    #     elif flag and not result:
    #         print(bu, index)
    #         flag = False

    # if np.sum(h) != np.sum(w):
    #     print(0)
    #     return
    # # else:
    #     # print(h, w)
    # for a in range(min(h[0], w[0]) + 1):
    #     for b in range(min(h[0], w[1]) + 1):
    #         for d in range(min(h[1], w[0]) + 1):
    #             for e in range(min(h[1], w[1]) + 1):
    #                 c = h[0] - a - b
    #                 f = h[1] - d - e
    #                 g = w[0] - a - d
    #                 hh = w[1] - b - e
    #                 i = h[2] - g - hh
    #                 # print(a, b, c, d, e, f, g, hh, i)
    #                 if i != w[2] - c - f:
    #                     continue
    #                 if c < 0 or f < 0 or g < 0 or hh < 0 or i < 0:
    #                     continue
    #                 count += 1
    # print(count)

    # pass
    # for i in range(n):
    # if np.sum(array[i:]) >= 4:
    # p += 1
    # print(p)


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n = int(lines[0])
    A = []
    for i, inputs in enumerate(lines[1:]):
        input = list(inputs)
        A.append(input)
        # rans.append([int(input[0]), int(input[1])])
    # hw = ([int(x) - 3 for x in lines[0].split(' ')])
    # h = hw[0:3]
    # w = hw[3:6]
    # print(h, w)
    main(n, A)
