'''
Très proche de la CWE 400, la CWE 834 s'assure qu'il n'y ai pas des boucles infinis
'''

import sys

def infinite_iter():
    i = 0
    while True:
        i += 1
        yield i


def unsafe(data, param):
    i = 0
    while True:
        if param == i:
            return
        print(next(data), i, param)
        i += 1


def safe(data, param):
    max_iterations=10
    i = 0
    while True:
        if param == i:
            return
        if i >= max_iterations:
            return
        print(next(data), i, param)
        i += 1


if __name__ == '__main__':
    param = sys.argv[1]

    #unsafe(infinite_iter(), int(param))
    safe(infinite_iter(), int(param))

# Usage nominal : python cli_sample.py 5
# faille : python cli_sample.py -1
