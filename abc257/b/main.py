import sys

import numpy as np


def main(n, k, q, an, ln):
    for l in ln:
        if an[l-1] == n:
            continue
        if l != k:
            if an[l-1] + 1 == an[l]:
                continue
        an[l-1] += 1
    print(' '.join(map(str, an)))


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, k, q = map(int, lines[0].split(' '))
    an = [int(i) for i in lines[1].split(' ')]
    ln = [int(i) for i in lines[2].split(' ')]
    main(n, k, q, an, ln)
