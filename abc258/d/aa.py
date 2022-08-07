import sys

if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    _, x = map(int, lines[0].split(' '))
    min_time = 1e20
    first_sum = 0
    for i, inputs in enumerate(lines[1:]):
        a, b = map(int, inputs.split(' '))
        first_sum += (a + b)
        if x - i - 1 >= 0:
            min_time = min(min_time, first_sum + (x - i - 1) * b)
    print(min_time)
