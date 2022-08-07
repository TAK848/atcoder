import sys

import numpy as np

if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, q, x = map(int, lines[0].split(' '))
    wi = list(map(int, lines[1].split(' ')))
    for query in lines[2:]:
        print(query)
