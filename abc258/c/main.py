import sys

if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, q = map(int, lines[0].split(' '))
    s = lines[1]
    start_index = 0
    # queries = []
    for query_str in lines[2:]:
        mode, num = map(int, query_str.split(' '))
        if mode == 1:
            start_index -= num
        elif mode == 2:
            print(s[(num - 1 + start_index) % n])
