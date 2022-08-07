import sys

import numpy as np

if __name__ == '__main__':
    lines = []
    listx = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, x = map(int, lines[0].split(' '))
    # print(2 ** int(lines[0]))
    a = int(np.ceil(x / n) - 1)
    print(listx[a])
