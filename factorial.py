import sys

def factorial(n):
    res = 1
    while n > 0:
        res = res * n
        n = n -1
    return res

if __name__ == "__main__":
    # n = int(input())
    n = sys.argv[1]
    res = factorial(int(n))
    print(n + "! = " + str(res))