import sys

if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    k = int(lines[0])
    print(f'{21 + k // 60:02d}:{k % 60:02d}')
