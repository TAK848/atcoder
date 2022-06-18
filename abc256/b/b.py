import sys

import numpy as np


def main(n, array):
    p = 0
    for i in range(n):
        if np.sum(array[i:]) >= 4:
            p += 1
    print(p)


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n = int(lines[0])
    array = np.array([int(x) for x in lines[1].split(' ')])
    main(n, array)
