import sys

import numpy as np


def main(n, q, a, queries):
    for query in queries:
        if query[0] == 1:
            a[query[1] - 1] = query[2]
        elif query[0] == 2:
            # b = np.zeros(n)
            # for i in range(n):
            #     b[i:] += a[i]
            b = np.cumsum(np.cumsum(np.cumsum(a, dtype=np.uint32),
                          dtype=np.uint32), dtype=np.uint32)
            # b = np.cumsum(b, dtype=np.uint64)
            # b = np.cumsum(b, dtype=np.uint64)
            # print(d, query[1])
            print(int(b[query[1] - 1] % 998244353))
            # print(b)
            # print(np.sum(a[query[1] - 1:query[2]]))


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, q = [int(x) for x in lines[0].split(' ')]
    a = np.array([int(x) for x in lines[1].split(' ')], dtype=np.uint32)
    queries = []
    for query in lines[2:]:
        query = [int(x) for x in query.split(' ')]
        if query[0] == 1:
            a[query[1] - 1] = query[2]
        elif query[0] == 2:
            # b = np.zeros(n)
            # for i in range(n):
            #     b[i:] += a[i]
            b = np.cumsum(np.cumsum(np.cumsum(a, dtype=np.uint32),
                          dtype=np.uint32), dtype=np.uint32)
            # b = np.cumsum(b, dtype=np.uint64)
            # b = np.cumsum(b, dtype=np.uint64)
            # print(d, query[1])
            print(int(b[query[1] - 1] % 998244353))
            # print(b)
            # print(np.sum(a[query[1] - 1:query[2]]))
