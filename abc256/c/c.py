import sys

import numpy as np


def main(h, w):
    count = 0

    if np.sum(h) != np.sum(w):
        print(0)
        return
    for a in range(min(h[0], w[0]) + 1):
        for b in range(min(h[0], w[1]) + 1):
            for d in range(min(h[1], w[0]) + 1):
                for e in range(min(h[1], w[1]) + 1):
                    c = h[0] - a - b
                    f = h[1] - d - e
                    g = w[0] - a - d
                    hh = w[1] - b - e
                    i = h[2] - g - hh
                    if i != w[2] - c - f:
                        continue
                    if c < 0 or f < 0 or g < 0 or hh < 0 or i < 0:
                        continue
                    count += 1
    print(count)


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    hw = ([int(x) - 3 for x in lines[0].split(' ')])
    h = hw[0:3]
    w = hw[3:6]
    main(h, w)
