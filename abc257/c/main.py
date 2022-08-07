import sys

import numpy as np


def main(n, s, wn):
    print(n, s, wn)
    max = int(1e10)
    min = 0
    adult_count_ans = np.count_nonzero(s)
    takahashi_ans = 0
    # mmm = 0
    # print(ans)
    while max - min > 1:
        mid = int((max + min) // 2)

        takahashi_adult = wn >= mid
        true_adult = takahashi_adult & s
        takahashi_adult_count = np.count_nonzero(takahashi_adult)
        true_adult_count = np.count_nonzero(true_adult)
        new_ans = np.count_nonzero(~ takahashi_adult ^ s)
        if n >= new_ans > takahashi_ans:
            takahashi_ans = new_ans
        print(min, mid, max, s, takahashi_adult, takahashi_adult_count, true_adult, true_adult_count, adult_count_ans,
              ~ takahashi_adult ^ s, new_ans, takahashi_ans)
        # break
        if true_adult_count < adult_count_ans:
            max = mid
        elif true_adult_count == adult_count_ans:
            min
        else:
            min = mid
    print(takahashi_ans)


if __name__ == '__main__':
    lines = []
    for line in sys.stdin:
        lines.append(line.rstrip('\r\n'))
    n, = map(int, lines[0].split(' '))
    s = [True if x == '1' else False for x in lines[1]]
    wn = np.array([int(i) for i in lines[2].split(' ')])
    main(n, s, wn)
