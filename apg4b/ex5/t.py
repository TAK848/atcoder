import sys

if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    a, b = map(int, lines[0].split(' '))
    print(a + b)
